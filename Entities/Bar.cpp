#include "Bar.h"

Bar::Bar(Scale scale, TimeSignature time)
{
	_scale = scale;
	_time = time;
}

Bar::Bar(BarOptions bOpts)
{
	_scale = bOpts.eScale;
	_time = bOpts.timeSignature;
	_octave = bOpts.octave;
	_octaves = bOpts.octaves;
}


TimeState Bar::CheckDuration() 
{
	float timeSum = 0;

	for(Note& n : _notes)
	{
		timeSum += n.GetTimeValue();
	}

	float sigValue = (((float)_time._top / (float)_time._bottom) * 4.0f);

	if (timeSum == sigValue)
	{
		return perfect;
	}
	else if (timeSum > sigValue)
	{
		return tooLong;
	}
	else
	{
		return tooShort;
	}
}

void Bar::GenerateNote(GeneratorOptions options)
{
	Note n = Note();

	GenerateNotePitch(n, options);
	GenerateNoteLength(n, options);
	GenerateNoteOctave(n, options);

	_notes.push_back(n);
}

void Bar::GenerateBar(GeneratorOptions options)
{
	GenerateNote(options);

	TimeState ret = CheckDuration();

	switch (ret)
	{
	case tooShort:
		GenerateBar(options);
		break;
	case tooLong:
		_notes.pop_back();
		GenerateBar(options);
		break;
	case perfect:
		break;
	default:
		break;
	}
}

void Bar::ClearBar()
{
	_notes.clear();
}

std::vector<Note> Bar::GetNotes()
{
	return _notes;
}

void Bar::GenerateNotePitch(Note& n, GeneratorOptions options)
{
	int pitch = lootcy.GetRandomInt(8) + 1;

	switch (pitch)
	{
	case 1:
	{
		n = options.useFirst ? _scale.GetFirst() : _scale.GetErr();
		break;
	}
	case 2:
	{
		n = options.useSecond ? _scale.GetSecond() : _scale.GetErr();
		break;
	}
	case 3:
	{
		n = options.useThird ? _scale.GetThird() : _scale.GetErr();
		break;
	}
	case 4:
	{
		n = options.useFourth ? _scale.GetFourth() : _scale.GetErr();
		break;
	}
	case 5:
	{
		n = options.useFifth ? _scale.GetFifth() : _scale.GetErr();
		break;
	}
	case 6:
	{
		n = options.useSixth ? _scale.GetSixth() : _scale.GetErr();
		break;
	}
	case 7:
	{
		n = options.useSeventh ? _scale.GetSeventh() : _scale.GetErr();
		break;
	}
	case 8:
	{
		n = options.useRest ? _scale.GetRest() : _scale.GetErr();
		break;
	}
	default:
		break;
	}

	if (n.IsError())
	{
		GenerateNotePitch(n, options);
	}
}

void Bar::GenerateNoteLength(Note& n, GeneratorOptions options)
{
	int length = lootcy.GetRandomInt(6);

	switch (length)
	{
	case 0:
	{
		options.includeWholeNote ? n.changeLength(whole) : n.changeLength(LengthErr);
		break;
	}
	case 1:
	{
		options.includeHalfNote ? n.changeLength(half) : n.changeLength(LengthErr);
		break;
	}
	case 2:
	{
		options.includeQuarterNote ? n.changeLength(quarter) : n.changeLength(LengthErr);
		break;
	}
	case 3:
	{
		options.includeEigthNote ? n.changeLength(eigth) : n.changeLength(LengthErr);
		break;
	}
	case 4:
	{
		options.includeSixteenthNote ? n.changeLength(sixteenth) : n.changeLength(LengthErr);
		break;
	}
	case 5:
	{
		options.includeThirtysecondNote ? n.changeLength(thirtysecond) : n.changeLength(LengthErr);
		break;
	}
	}

	if (n.GetLength() == LengthErr)
	{
		GenerateNoteLength(n, options);
	}
}

void Bar::GenerateNoteOctave(Note& n, GeneratorOptions options)
{
	if (options.usingOctaves)
	{
		int octave = lootcy.GetRandomInt(_octaves);

		octave = _octave + octave;

		octave > 7 ? octave = 7 : octave = octave;
		octave < 0 ? octave = 0 : octave = octave;

		n.changeOctave(octave);
	}
	else
	{
		n.changeOctave(4);
	}
}