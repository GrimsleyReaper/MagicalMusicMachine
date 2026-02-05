#pragma once

#include "Note.h"

class Scale
{
private:
	Pitch _pitch;
	Tonality _tone;
	ScaleType _type;
	Note _notes[7];
	
	void makeScale(Pitch pitch, Tonality tone, ScaleType type);
	void makeMajorScale(Pitch pitch, Tonality tone);
	void makeMinorScale(Pitch pitch, Tonality tone);
	void makeMixolydianScale(Pitch pitch, Tonality tone);

public:

	Scale() = default;

	Scale(Pitch pitch, Tonality tone, ScaleType type);

	Note GetFirst();
	Note GetSecond();
	Note GetThird();
	Note GetFourth();
	Note GetFifth();
	Note GetSixth();
	Note GetSeventh();
	Note GetRest();
	Note GetErr();
};

