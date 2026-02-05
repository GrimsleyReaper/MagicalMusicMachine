#pragma once

#include "Section.h"
#include <string>
#include <vector>

class Track
{
private:

public:
	
	std::vector<Section> _sections;
	std::string name;

	void AddSection(BarOptions bOpts, int barNum, int repeats, std::string name);
	void AddSection(Section s);
	void AddDuplicateSection(int sectionPos);

	void GenerateSections(GeneratorOptions gOptions);

	void RemoveSection(int sectionPos);
	void ClearSections();

	std::string GetNextSectionNo();

};