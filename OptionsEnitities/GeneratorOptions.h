#pragma once

class GeneratorOptions
{
private:

public:

	// Length
	bool includeWholeNote = true;
	bool includeHalfNote = true;
	bool includeQuarterNote = true;
	bool includeEigthNote = true;
	bool includeSixteenthNote = true;
	bool includeThirtysecondNote = true;

	//Pitch
	bool useFirst = true;
	bool useSecond = true;
	bool useThird = true;
	bool useFourth = true;
	bool useFifth = true;
	bool useSixth = true;
	bool useSeventh = true;
	bool useRest = true;

	//Octave
	bool usingOctaves = true;
};