#include "Section.h"

void Section::GenerateBars(GeneratorOptions gOptions)
{
	for (int i = 0; i < numBars; i++)
	{
		Bar temp;
		bOptions.ConvertToEnums();
		temp = Bar(bOptions);
		temp.GenerateBar(gOptions);
		_bars.push_back(temp);
	}

	if (repeats > 0)
	{
		for (size_t i = 0; i < repeats; i++)
		{
			for (size_t i = 0; i < numBars; i++)
			{
				Bar temp = Bar(_bars[i]);
				_bars.push_back(temp);
			}
		}
	}
}

void Section::ClearBars()
{
	_bars.clear();
}

std::vector<Bar> Section::GetBars()
{
	return _bars;
}