#include "Note.h"

Note::Note(NoteInfo info)
{
	_pitch = info._pitch;
	_length = info._length;
	_tone = info._tone;
	_octave = info._octave;
}

void Note::moveUp() 
{
	if (_octave < 7 ) {
		_octave++;
	}
}

void Note::moveDown()
{
	if (_octave >= 1) {
		_octave--;
	}
}

float Note::GetTimeValue()
{
	return ( 1.0f / (float)_length ) * 4.0f;
}

void Note::changeLength(Length length)
{
	_length = length;
}

void Note::changeOctave(int octave)
{
	_octave = octave;
}

std::string Note::ToString(GeneratorOptions opts)
{
	std::string ret = "";

	switch (_pitch)
	{
	case REST:
		ret = "Rest";
		break;
	case C:
		ret = "C";
		break;
	case D:
		ret = "D";
		break;
	case E:
		ret = "E";
		break;
	case F:
		ret = "F";
		break;
	case G:
		ret = "G";
		break;
	case A:
		ret = "A";
		break;
	case B:
		ret = "B";
		break;
	default:
		break;
	}

	if (_pitch != REST)
	{
		switch (_tone)
		{
		case doubleFlat:
			ret += "bb";
			break;
		case flat:
			ret += "b";
			break;
		case neutral:
			break;
		case sharp:
			ret += "#";
			break;
		case doubleSharp:
			ret += "##";
			break;
		default:
			break;
		}
	}

	if (_pitch != REST && opts.usingOctaves)
	{
		ret += std::to_string(_octave);
	}

	switch (_length)
	{
	case whole:
		ret += " Whole";
		break;
	case half:
		ret += " Half";
		break;
	case quarter:
		ret += " Quarter";
		break;
	case eigth:
		ret += " Eigth";
		break;
	case sixteenth:
		ret += " Sixteenth";
		break;
	case thirtysecond:
		ret += " Thirtysecond";
		break;
	default:
		break;
	}

	return ret;
}

Length Note::GetLength()
{
	return _length;
}

bool Note::IsError()
{
	return _pitch == PitchErr;
}