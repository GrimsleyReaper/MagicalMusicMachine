// Dear ImGui: standalone example application for DirectX 11
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs

#include "imgui/imgui.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_dx11.h"
#include "imgui/imgui_stdlib.h"
#include <d3d11.h>
#include <tchar.h>
#include <string>
#include "OptionsEnitities/BarOptions.h"
#include "OptionsEnitities/GeneratorOptions.h"
#include "Entities/Track.h"

// Data
static ID3D11Device*            g_pd3dDevice = NULL;
static ID3D11DeviceContext*     g_pd3dDeviceContext = NULL;
static IDXGISwapChain*          g_pSwapChain = NULL;
static ID3D11RenderTargetView*  g_mainRenderTargetView = NULL;

// Forward declarations of helper functions
bool CreateDeviceD3D(HWND hWnd);
void CleanupDeviceD3D();
void CreateRenderTarget();
void CleanupRenderTarget();
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Sub Menu Functs
void DuplicateSectionSubMenu(Track& t);
void RemoveSectionSubMenu(Track& t);
void RenameSectionMenu(Track& t, int& idHolder, bool& showEditor, std::string& nameHolder);
void RenameTrackMenu(std::vector<Track>& tracks, int& idHolder, bool& showEditor, std::string& nameHolder);
void GenerateSectionSubMenu(Track& t, GeneratorOptions gOpts);

// Gen Opts Profiles
void SetGenOptsDoom(GeneratorOptions& opts);
void SetGenOptsDrone(GeneratorOptions& opts);
void SetGenOptsRestless(GeneratorOptions& opts);
void SetGenOptsPop(GeneratorOptions& opts);

// Main code
int main(int, char**)
{
    // Create application window
    //ImGui_ImplWin32_EnableDpiAwareness();
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, _T("ImGui Example"), NULL };
    ::RegisterClassEx(&wc);
    HWND hwnd = ::CreateWindow(wc.lpszClassName, _T("Lexi's Magical Music Device"), WS_OVERLAPPEDWINDOW, 100, 100, 1280, 800, NULL, NULL, wc.hInstance, NULL);

    // Initialize Direct3D
    if (!CreateDeviceD3D(hwnd))
    {
        CleanupDeviceD3D();
        ::UnregisterClass(wc.lpszClassName, wc.hInstance);
        return 1;
    }

    // Show the window
    ::ShowWindow(hwnd, SW_SHOWDEFAULT);
    ::UpdateWindow(hwnd);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();

    // Setup Platform/Renderer backends
    ImGui_ImplWin32_Init(hwnd);
    ImGui_ImplDX11_Init(g_pd3dDevice, g_pd3dDeviceContext);

    // Load Fonts
    // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
    // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
    // - If the file cannot be loaded, the function will return NULL. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
    // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
    // - Read 'docs/FONTS.md' for more instructions and details.
    // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
    //io.Fonts->AddFontDefault();
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/ProggyTiny.ttf", 10.0f);
    //ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());
    //IM_ASSERT(font != NULL);

    // Our state
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    const ImGuiViewport* main_viewport = ImGui::GetMainViewport();

    // Options
    GeneratorOptions genOptions;

    // Data State
    std::vector<Track> tracks;
    int selectedTrack = 0;
    int currentEditSection = 0;
    int currentEditTrack = 0;
    std::string newNameForEdit = "";

    // View State
    bool showSections = false;
    bool showSectionEdit = false;
    bool showTrackEdit = false;
  
    // Set Defaults
    Track t;
    t.name = "Default";
    tracks.push_back(t);

    // Variable Arrays
    const std::string pitchNames[7] = { "C", "D", "E", "F", "G", "A", "B" };
    const std::string toneNames[3] = { "Flat", "Neutral", "Sharp" };
    const std::string scaleNames[3] = { "Major", "Minor", "Mixolydian" };
    const std::string timeTopNames[6] = { "2", "3", "4", "7", "8", "12" };
    const std::string timeBottomNames[3] = { "2", "4", "8" };

    // Main loop
    bool done = false;
    while (!done)
    {
        // Poll and handle messages (inputs, window resize, etc.)
        // See the WndProc() function below for our to dispatch events to the Win32 backend.
        MSG msg;
        while (::PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
            if (msg.message == WM_QUIT)
                done = true;
        }
        if (done)
            break;

        // Start the Dear ImGui frame
        ImGui_ImplDX11_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();

        if (ImGui::BeginMainMenuBar())
        {
            if (ImGui::BeginMenu("File"))
            {
                if (ImGui::MenuItem("New Track")) {
                    Track t;

                    t.name = "Track " + std::to_string(tracks.size());
                    tracks.push_back(t);
                }

                ImGui::EndMenu();
            }
            ImGui::EndMainMenuBar();
        }

        ImGuiWindowFlags designerFlags = 0;
        designerFlags |= ImGuiWindowFlags_NoCollapse;
        designerFlags |= ImGuiWindowFlags_NoResize;
        designerFlags |= ImGuiWindowFlags_MenuBar;

        ImGui::SetNextWindowPos(ImVec2(main_viewport->WorkPos.x, main_viewport->WorkPos.y), ImGuiCond_Always);
        ImGui::SetNextWindowSize(ImVec2((main_viewport->WorkSize.x * 0.33f), main_viewport->WorkSize.y), ImGuiCond_Always);

        ImGui::Begin("Sections Designer", NULL, designerFlags);
        
        if (ImGui::BeginMenuBar())
        {
            if (ImGui::BeginMenu("Actions"))
            {
                if (ImGui::MenuItem("Add Section")) {
                    Section s;

                    s.name = "Section " + tracks[selectedTrack].GetNextSectionNo();
                    tracks[selectedTrack].AddSection(s);
                }

                if (ImGui::BeginMenu("Duplicate Section"))
                {
                    DuplicateSectionSubMenu(tracks[selectedTrack]);

                    ImGui::EndMenu();
                }

                if (ImGui::BeginMenu("Rename Section"))
                {
                    RenameSectionMenu(tracks[selectedTrack], currentEditSection, showSectionEdit, newNameForEdit);

                    ImGui::EndMenu();
                }

                if (ImGui::BeginMenu("Remove Section"))
                {
                    RemoveSectionSubMenu(tracks[selectedTrack]);

                    ImGui::EndMenu();
                }

                if (ImGui::MenuItem("Clear Sections")) {
                    tracks[selectedTrack].ClearSections();
                }

                ImGui::EndMenu();
            }

            if (ImGui::BeginMenu("Generate"))
            {
                if (ImGui::MenuItem("Generate Sections")) {
                    tracks[selectedTrack].GenerateSections(genOptions);
                    showSections = true;
                }

                if (ImGui::BeginMenu("Regenerate Section"))
                {
                    GenerateSectionSubMenu(tracks[selectedTrack], genOptions);

                    ImGui::EndMenu();
                }

                ImGui::EndMenu();
            }

            ImGui::EndMenuBar();
        }

        if (showSectionEdit)
        {
            std::string title = tracks[selectedTrack]._sections[currentEditSection].name + " edit";
            ImGui::Text(title.c_str());
            ImGui::InputTextWithHint("Name", "Enter new name...", &newNameForEdit);

            ImGui::Text("Please ensure that section names are unique!!");

            if (ImGui::Button("Ok", ImVec2(50, 50)))
            {
                tracks[selectedTrack]._sections[currentEditSection].name = newNameForEdit;
                showSectionEdit = false;
            }
        }

        for (Section& s : tracks[selectedTrack]._sections)
        {
            ImGui::SetNextItemOpen(true, ImGuiCond_Appearing);

            if (ImGui::TreeNode(s.name.c_str()))
            {
                if (ImGui::BeginListBox("Pitch"))
                {
                    for (int n = 0; n < 7; n++)
                    {
                        if (ImGui::Selectable(pitchNames[n].c_str(), s.bOptions.pitch == n))
                            s.bOptions.pitch = n;
                    }
                    ImGui::EndListBox();
                }

                if (ImGui::BeginListBox("Tone"))
                {
                    for (int n = 0; n < 3; n++)
                    {
                        if (ImGui::Selectable(toneNames[n].c_str(), s.bOptions.tone == n))
                            s.bOptions.tone = n;
                    }
                    ImGui::EndListBox();
                }

                if (ImGui::BeginListBox("Scale"))
                {
                    for (int n = 0; n < 3; n++)
                    {
                        if (ImGui::Selectable(scaleNames[n].c_str(), s.bOptions.scaleType == n))
                            s.bOptions.scaleType = n;
                    }
                    ImGui::EndListBox();
                }

                if (genOptions.usingOctaves)
                {
                    ImGui::InputInt("Octave (lowest)", &s.bOptions.octave);
                    ImGui::InputInt("Number of Octaves (Up)", &s.bOptions.octaves);
                }

                if (ImGui::BeginListBox("Signature Top"))
                {
                    for (int n = 0; n < 6; n++)
                    {
                        if ((n != 1 && n != 3) || (genOptions.includeEigthNote || genOptions.includeSixteenthNote || genOptions.includeThirtysecondNote))
                        {
                            if (ImGui::Selectable(timeTopNames[n].c_str(), s.bOptions.timeTop == n))
                                s.bOptions.timeTop = n;
                        }
                    }
                    ImGui::EndListBox();
                }

                if (ImGui::BeginListBox("Signature Bottom"))
                {
                    for (int n = 0; n < 3; n++)
                    {
                        if (ImGui::Selectable(timeBottomNames[n].c_str(), s.bOptions.timeBottom == n))
                            s.bOptions.timeBottom = n;
                    }
                    ImGui::EndListBox();
                }

                ImGui::InputInt("Number of Bars", &s.numBars);
                ImGui::InputInt("Number of Repeats", &s.repeats);

                ImGui::TreePop();
            }
        }

        ImGui::End();

        if (showSections)
        {
            ImGuiWindowFlags sectViewerFlags = 0;
            sectViewerFlags |= ImGuiWindowFlags_NoCollapse;
            sectViewerFlags |= ImGuiWindowFlags_NoResize;

            ImGui::SetNextWindowPos(ImVec2((main_viewport->WorkPos.x + (main_viewport->WorkSize.x * 0.33f)), main_viewport->WorkPos.y), ImGuiCond_Always);
            ImGui::SetNextWindowSize(ImVec2((main_viewport->WorkSize.x * 0.47f), (main_viewport->WorkSize.y * 0.75f)), ImGuiCond_Always);

            ImGui::Begin("Section Viewer", NULL, sectViewerFlags);
            for (Section& s : tracks[selectedTrack]._sections)
            {
                std::string nameDisplay = "------ " + s.name + " ------";

                ImGui::Text(nameDisplay.c_str());

                for (Bar b : s.GetBars())
                {
                    for (Note n : b.GetNotes())
                    {
                        ImGui::Text(n.ToString(genOptions).c_str());
                    }

                    ImGui::Text("----------");
                }
            }
            ImGui::End();
        }

        ImGuiWindowFlags GenOptFlags = 0;
        GenOptFlags |= ImGuiWindowFlags_NoCollapse;
        GenOptFlags |= ImGuiWindowFlags_NoResize;
        GenOptFlags |= ImGuiWindowFlags_MenuBar;

        ImGui::SetNextWindowPos(ImVec2((main_viewport->WorkPos.x + (main_viewport->WorkSize.x * 0.8f)), main_viewport->WorkPos.y), ImGuiCond_Always);
        ImGui::SetNextWindowSize(ImVec2((main_viewport->WorkSize.x * 0.2f), (main_viewport->WorkSize.y * 0.6f)), ImGuiCond_Always);

        ImGui::Begin("Generation Options", NULL, GenOptFlags);

        if (ImGui::BeginMenuBar())
        {
            if (ImGui::BeginMenu("Profiles"))
            {
                if (ImGui::MenuItem("Doom Metal")) {
                    SetGenOptsDoom(genOptions);
                }

                if (ImGui::MenuItem("Drone")) {
                    SetGenOptsDrone(genOptions);
                }

                if (ImGui::MenuItem("Restless")) {
                    SetGenOptsRestless(genOptions);
                }

                if (ImGui::MenuItem("Pop")) {
                    SetGenOptsPop(genOptions);
                }

                ImGui::EndMenu();
            }

            ImGui::EndMenuBar();
        }

        ImGui::Text("Length Preferences");

        ImGui::Checkbox("Use Whole Notes", &genOptions.includeWholeNote);
        ImGui::Checkbox("Use Half Notes", &genOptions.includeHalfNote);
        ImGui::Checkbox("Use Quarter Notes", &genOptions.includeQuarterNote);
        ImGui::Checkbox("Use Eigth Notes", &genOptions.includeEigthNote);
        ImGui::Checkbox("Use Sixteenth Notes", &genOptions.includeSixteenthNote);
        ImGui::Checkbox("Use Thirty Second Notes", &genOptions.includeThirtysecondNote);

        ImGui::Text("Scale Preferences");

        ImGui::Checkbox("Use First", &genOptions.useFirst);
        ImGui::Checkbox("Use Second", &genOptions.useSecond);
        ImGui::Checkbox("Use Third", &genOptions.useThird);
        ImGui::Checkbox("Use Fourth", &genOptions.useFourth);
        ImGui::Checkbox("Use Fifth", &genOptions.useFifth);
        ImGui::Checkbox("Use Sixth", &genOptions.useSixth);
        ImGui::Checkbox("Use Seventh", &genOptions.useSeventh);
        ImGui::Checkbox("Use Rest", &genOptions.useRest);

        ImGui::Text("Octave Preferences");

        ImGui::Checkbox("Using Octaves", &genOptions.usingOctaves);

        ImGui::End();

        ImGuiWindowFlags tracksViewFlags = 0;
        tracksViewFlags |= ImGuiWindowFlags_NoCollapse;
        tracksViewFlags |= ImGuiWindowFlags_NoResize;
        tracksViewFlags |= ImGuiWindowFlags_MenuBar;

        ImGui::SetNextWindowPos(ImVec2((main_viewport->WorkPos.x + (main_viewport->WorkSize.x * 0.33f)), (main_viewport->WorkPos.y + (main_viewport->WorkSize.y * 0.75f))), ImGuiCond_Always);
        ImGui::SetNextWindowSize(ImVec2((main_viewport->WorkSize.x * 0.47f), (main_viewport->WorkSize.y * 0.25f)), ImGuiCond_Always);

        ImGui::Begin("Tracks", NULL, tracksViewFlags);

        if (ImGui::BeginMenuBar())
        {
            if (ImGui::BeginMenu("Actions"))
            {
                if (ImGui::MenuItem("New Track")) {
                    Track t;

                    t.name = "Track " + std::to_string(tracks.size() + 1);
                    tracks.push_back(t);
                }

                if (ImGui::BeginMenu("Rename Track"))
                {
                    RenameTrackMenu(tracks, currentEditTrack, showTrackEdit, newNameForEdit);

                    ImGui::EndMenu();
                }

                ImGui::EndMenu();
            }
            ImGui::EndMenuBar();
        }

        if (showTrackEdit)
        {
            std::string title = tracks[currentEditTrack].name + " edit";
            ImGui::Text(title.c_str());

            ImGui::InputTextWithHint("Name", "Enter new name...", &newNameForEdit);

            ImGui::Text("Please ensure that track names are unique!!");

            if (ImGui::Button("Ok", ImVec2(50, 50)))
            {
                tracks[currentEditTrack].name = newNameForEdit;
                showTrackEdit = false;
            }
        }

        for (int n = 0; n < tracks.size(); n++)
        {
            if (ImGui::Selectable(tracks[n].name.c_str(), selectedTrack == n))
                selectedTrack = n;
            std::string sections = "  Sections : ";
            for (Section s : tracks[n]._sections)
            {
                sections += s.name + ", ";
            }
            sections = sections.substr(0, sections.size() - 2);
            ImGui::Text(sections.c_str());
        }

        ImGui::End();

        // Rendering
        ImGui::Render();
        const float clear_color_with_alpha[4] = { clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w };
        g_pd3dDeviceContext->OMSetRenderTargets(1, &g_mainRenderTargetView, NULL);
        g_pd3dDeviceContext->ClearRenderTargetView(g_mainRenderTargetView, clear_color_with_alpha);
        ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

        g_pSwapChain->Present(1, 0); // Present with vsync
        //g_pSwapChain->Present(0, 0); // Present without vsync
    }

    // Cleanup
    ImGui_ImplDX11_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    CleanupDeviceD3D();
    ::DestroyWindow(hwnd);
    ::UnregisterClass(wc.lpszClassName, wc.hInstance);

    return 0;
}

// Helper functions

bool CreateDeviceD3D(HWND hWnd)
{
    // Setup swap chain
    DXGI_SWAP_CHAIN_DESC sd;
    ZeroMemory(&sd, sizeof(sd));
    sd.BufferCount = 2;
    sd.BufferDesc.Width = 0;
    sd.BufferDesc.Height = 0;
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sd.OutputWindow = hWnd;
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    sd.Windowed = TRUE;
    sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

    UINT createDeviceFlags = 0;
    //createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
    D3D_FEATURE_LEVEL featureLevel;
    const D3D_FEATURE_LEVEL featureLevelArray[2] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0, };
    if (D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags, featureLevelArray, 2, D3D11_SDK_VERSION, &sd, &g_pSwapChain, &g_pd3dDevice, &featureLevel, &g_pd3dDeviceContext) != S_OK)
        return false;

    CreateRenderTarget();
    return true;
}

void CleanupDeviceD3D()
{
    CleanupRenderTarget();
    if (g_pSwapChain) { g_pSwapChain->Release(); g_pSwapChain = NULL; }
    if (g_pd3dDeviceContext) { g_pd3dDeviceContext->Release(); g_pd3dDeviceContext = NULL; }
    if (g_pd3dDevice) { g_pd3dDevice->Release(); g_pd3dDevice = NULL; }
}

void CreateRenderTarget()
{
    ID3D11Texture2D* pBackBuffer;
    g_pSwapChain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));
    g_pd3dDevice->CreateRenderTargetView(pBackBuffer, NULL, &g_mainRenderTargetView);
    pBackBuffer->Release();
}

void CleanupRenderTarget()
{
    if (g_mainRenderTargetView) { g_mainRenderTargetView->Release(); g_mainRenderTargetView = NULL; }
}

// Forward declare message handler from imgui_impl_win32.cpp
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Win32 message handler
// You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
// - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
// - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
// Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
        {
            CleanupRenderTarget();
            g_pSwapChain->ResizeBuffers(0, (UINT)LOWORD(lParam), (UINT)HIWORD(lParam), DXGI_FORMAT_UNKNOWN, 0);
            CreateRenderTarget();
        }
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
            return 0;
        break;
    case WM_DESTROY:
        ::PostQuitMessage(0);
        return 0;
    }
    return ::DefWindowProc(hWnd, msg, wParam, lParam);
}

void DuplicateSectionSubMenu(Track& t)
{
    for (int i = 0; i < t._sections.size(); i++)
    {
        if (ImGui::MenuItem(t._sections[i].name.c_str())) {
            t.AddDuplicateSection(i);
        }
    }
}

void RemoveSectionSubMenu(Track& t)
{
    for (int i = 0; i < t._sections.size(); i++)
    {
        if (ImGui::MenuItem(t._sections[i].name.c_str())) {
            t.RemoveSection(i);
        }
    }
}

void RenameSectionMenu(Track& t, int& idHolder, bool& showEditor, std::string& nameHolder)
{
    for (int i = 0; i < t._sections.size(); i++)
    {
        if (ImGui::MenuItem(t._sections[i].name.c_str())) {
            idHolder = i;
            showEditor = true;
            nameHolder = "";
        }
    }
}

void RenameTrackMenu(std::vector<Track>& tracks, int& idHolder, bool& showEditor, std::string& nameHolder)
{
    for (int i = 0; i < tracks.size(); i++)
    {
        if (ImGui::MenuItem(tracks[i].name.c_str())) {
            idHolder = i;
            showEditor = true;
            nameHolder = "";
        }
    }
}

void GenerateSectionSubMenu(Track& t, GeneratorOptions gOpts)
{
    for (int i = 0; i < t._sections.size(); i++)
    {
        if (ImGui::MenuItem(t._sections[i].name.c_str())) {
            t._sections[i].ClearBars();
            t._sections[i].GenerateBars(gOpts);
        }
    }
}

void SetGenOptsDoom(GeneratorOptions& opts)
{
    //Length
    opts.includeWholeNote = opts.includeHalfNote = opts.includeQuarterNote = opts.includeEigthNote = true;
    opts.includeSixteenthNote = opts.includeThirtysecondNote = false;

    //Pitch
    opts.useFirst = opts.useSecond = opts.useThird = opts.useFourth = opts.useFifth =
        opts.useSixth = opts.useSeventh = opts.useRest = true;

    //Octaves
    opts.usingOctaves = true;
}

void SetGenOptsDrone(GeneratorOptions& opts)
{
    //Length
    opts.includeWholeNote = true;
    opts.includeHalfNote = opts.includeQuarterNote = opts.includeEigthNote = opts.includeSixteenthNote = opts.includeThirtysecondNote = false;

    //Pitch
    opts.useFirst = opts.useSecond = opts.useThird = opts.useFourth = opts.useFifth =
        opts.useSixth = opts.useSeventh = opts.useRest = true;

    //Octaves
    opts.usingOctaves = true;
}

void SetGenOptsRestless(GeneratorOptions& opts)
{
    //Length
    opts.includeWholeNote = opts.includeHalfNote = opts.includeQuarterNote = opts.includeEigthNote =
        opts.includeSixteenthNote = opts.includeThirtysecondNote = true;

    //Pitch
    opts.useFirst = opts.useSecond = opts.useThird = opts.useFourth = opts.useFifth =
        opts.useSixth = opts.useSeventh = true;
    opts.useRest = false;

    //Octaves
    opts.usingOctaves = true;
}

void SetGenOptsPop(GeneratorOptions& opts)
{
    //Length
    opts.includeWholeNote = opts.includeHalfNote = opts.includeQuarterNote = true;
    opts.includeEigthNote = opts.includeSixteenthNote = opts.includeThirtysecondNote = false;

    //Pitch
    opts.useFirst = opts.useThird = opts.useFourth = opts.useFifth = opts.useSeventh = opts.useRest = true; 
    opts.useSecond = opts.useSixth = false;

    //Octaves
    opts.usingOctaves = true;
}