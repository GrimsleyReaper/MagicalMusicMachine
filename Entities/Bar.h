#pragma once

#include "Scale.h"
#include <vector>
#include "../Utils/Lootcifer.h"
#include "../OptionsEnitities/BarOptions.h"
#include "../OptionsEnitities/GeneratorOptions.h"

class Bar
{
private:

	Scale _scale = Scale(C, neutral, Major);
	TimeSignature _time;
	int _octave = 4;
	int _octaves = 1;
	std::vector<Note> _notes;

	Lootcifer lootcy;

	TimeState CheckDuration();

	void GenerateNote(GeneratorOptions options);
	void GenerateNotePitch(Note& n, GeneratorOptions options);
	void GenerateNoteLength(Note& n, GeneratorOptions options);
	void GenerateNoteOctave(Note& n, GeneratorOptions options);

public:

	Bar() = default;

	Bar(Scale scale, TimeSignature time);

	Bar(BarOptions options);

	void GenerateBar(GeneratorOptions options);
	void ClearBar();

	std::vector<Note> GetNotes();
};