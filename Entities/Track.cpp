#include "Track.h"

void Track::AddSection(BarOptions bOpts, int barNum, int repeats, std::string name)
{
	Section temp;
	temp.bOptions = bOpts;
	temp.numBars = barNum;
	temp.repeats = repeats;
	temp.name = name;
	_sections.push_back(temp);
}

void Track::AddDuplicateSection(int sectionPos)
{
	Section temp = Section(_sections[sectionPos]);
	temp.name += " (1)";

	_sections.push_back(temp);
}

void Track::AddSection(Section s)
{
	_sections.push_back(s);
}

void Track::GenerateSections(GeneratorOptions gOptions)
{
	for (Section& s : _sections)
	{
		s.ClearBars();
		s.GenerateBars(gOptions);
	}
}

std::string Track::GetNextSectionNo()
{
	return std::to_string(_sections.size());
}

void Track::ClearSections()
{
	_sections.clear();
}

void Track::RemoveSection(int sectionPos)
{
	std::vector<Section> temp;
	
	for (int i = 0; i < _sections.size(); i++)
	{
		if (i != sectionPos)
		{
			temp.push_back(_sections[i]);
		}
	}

	_sections = temp;
}