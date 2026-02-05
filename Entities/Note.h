#pragma once

#include "../Enums/Enums.h"
#include "../OptionsEnitities/GeneratorOptions.h"
#include <string>

struct NoteInfo
{
	Pitch _pitch = C;
	Tonality _tone = neutral;
	Length _length = quarter;
	int _octave = 4;
};

class Note
{
private:

	Pitch _pitch;
	Tonality _tone;
	Length _length;
	int _octave;

public:

	Note() = default;

	Note(const Note&) = default;

	Note(NoteInfo info);

	void moveUp();

	void moveDown();

	void changeLength(Length length);

	void changeOctave(int octave);

	float GetTimeValue();

	std::string ToString(GeneratorOptions opts);

	Length GetLength();

	bool IsError();
};