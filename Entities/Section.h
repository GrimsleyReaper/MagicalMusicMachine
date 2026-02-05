#pragma once

#include "Bar.h"
#include <string>
#include <vector>
#include "../OptionsEnitities/BarOptions.h"
#include "../OptionsEnitities/GeneratorOptions.h"

class Section
{
private:
	std::vector<Bar> _bars;

public:
	
	std::string name = "Section";
	int numBars = 1;
	int repeats = 1;

	BarOptions bOptions;

	void GenerateBars(GeneratorOptions gOptions);
	std::vector<Bar> GetBars();
	void ClearBars();
};
