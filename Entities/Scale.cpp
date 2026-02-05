#include "Scale.h"

Scale::Scale(Pitch pitch, Tonality tone, ScaleType type)
{
	makeScale(pitch, tone, type);
}

void Scale::makeScale(Pitch pitch, Tonality tone, ScaleType type)
{
	switch (type)
	{
	case Major:
		makeMajorScale(pitch, tone);
		break;
	case Minor:
		makeMinorScale(pitch, tone);
		break;
	case Mixolydian:
		makeMixolydianScale(pitch, tone);
		break;
	default:
		break;
	}
}

void Scale::makeMajorScale(Pitch pitch, Tonality tone)
{
	switch (pitch)
	{
	case C:
		switch (tone)
		{
		case flat:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Major;

			Pitch pitches[7] = { C, D, E, F, G, A, B };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], flat, quarter, 4 });
			}

			break;
		}
		case neutral:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Major;

			Pitch pitches[7] = { C, D, E, F, G, A, B };
			
			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], neutral, quarter, 4 });
			}

			break;
		}
		case sharp:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Major;

			Pitch pitches[7] = { C, D, E, F, G, A, B };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], sharp, quarter, 4 });
			}

			break;
		}
		default:
			break;
		}
		break;
	case D:
		switch (tone)
		{
		case flat:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Major;

			Pitch pitches[7] = { D, E, F, G, A, B, C };
			Tonality tones[7] = { flat, flat, neutral, flat, flat, flat, neutral };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4});
			}

			break;
		}
		case neutral:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Major;

			Pitch pitches[7] = { D, E, F, G, A, B, C };
			Tonality tones[7] = { neutral, neutral, sharp, neutral, neutral, neutral, sharp };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4});
			}

			break;
		}
		case sharp:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Major;

			Pitch pitches[7] = { D, E, F, G, A, B, C };
			Tonality tones[7] = { neutral, flat, neutral, neutral, flat, flat, neutral };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4});
			}

			break;
		}
		default:
			break;
		}
		break;
	case E:
		switch (tone)
		{
		case flat:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Major;

			Pitch pitches[7] = { E, F, G, A, B, C, D };
			Tonality tones[7] = { flat, neutral, neutral, flat, flat, neutral, neutral };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		case neutral:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Major;

			Pitch pitches[7] = { E, F, G, A, B, C, D };
			Tonality tones[7] = { neutral, sharp, sharp, neutral, neutral, sharp, sharp };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		case sharp:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Major;

			Pitch pitches[7] = { E, F, G, A, B, C, D };
			Tonality tones[7] = { sharp, doubleSharp, doubleSharp, sharp, sharp, doubleSharp, doubleSharp };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		default:
			break;
		}
		break;
	case F:
		switch (tone)
		{
		case flat:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Major;

			Pitch pitches[7] = { F, G, A, B, C, D, E };
			Tonality tones[7] = { flat, flat, flat, doubleFlat, flat, flat, flat };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		case neutral:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Major;

			Pitch pitches[7] = { F, G, A, B, C, D, E };
			Tonality tones[7] = { neutral, neutral, neutral, flat, neutral, neutral, neutral };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		case sharp:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Major;

			Pitch pitches[7] = { F, G, A, B, C, D, E };
			Tonality tones[7] = { sharp, sharp, sharp, neutral, sharp, sharp, sharp};

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		default:
			break;
		}
		break;
	case G:
		switch (tone)
		{
		case flat:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Major;

			Pitch pitches[7] = { G, A, B, C, D, E, F };
			Tonality tones[7] = { flat, flat, flat, flat, flat, flat, neutral };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		case neutral:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Major;

			Pitch pitches[7] = { G, A, B, C, D, E, F };
			Tonality tones[7] = { neutral, neutral, neutral, neutral, neutral, neutral, sharp };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		case sharp:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Major;

			Pitch pitches[7] = { G, A, B, C, D, E, F };
			Tonality tones[7] = { sharp, sharp, sharp, sharp, sharp, sharp, doubleSharp };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		default:
			break;
		}
		break;
	case A:
		switch (tone)
		{
		case flat:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Major;

			Pitch pitches[7] = { A, B, C, D, E, F, G };
			Tonality tones[7] = { flat, flat, neutral, flat, flat, neutral, neutral };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		case neutral:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Major;

			Pitch pitches[7] = { A, B, C, D, E, F, G };
			Tonality tones[7] = { neutral, neutral, sharp, neutral, neutral, sharp, sharp };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		case sharp:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Major;

			Pitch pitches[7] = { A, B, C, D, E, F, G };
			Tonality tones[7] = { sharp, sharp, doubleSharp, sharp, sharp, doubleSharp, doubleSharp };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		default:
			break;
		}
		break;
	case B:
		switch (tone)
		{
		case flat:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Major;

			Pitch pitches[7] = { B, C, D, E, F, G, A };
			Tonality tones[7] = { flat, neutral, neutral, flat, neutral, neutral, neutral };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		case neutral: 
		{
			_pitch = pitch;
			_tone = tone;
			_type = Major;

			Pitch pitches[7] = { B, C, D, E, F, G, A };
			Tonality tones[7] = { neutral, sharp, sharp, neutral, sharp, sharp, sharp };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		case sharp:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Major;

			Pitch pitches[7] = { B, C, D, E, F, G, A };
			Tonality tones[7] = { sharp, doubleSharp, doubleSharp, sharp, doubleSharp, doubleSharp, doubleSharp };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void Scale::makeMinorScale(Pitch pitch, Tonality tone)
{
	switch (pitch)
	{
	case C:
		switch (tone)
		{
		case flat:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Minor;

			Pitch pitches[7] = { C, D, E, F, G, A, B };
			Tonality tones[7] = { flat, flat, doubleFlat, flat, flat, doubleFlat, doubleFlat };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4});
			}

			break;
		}
		case neutral:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Minor;

			Pitch pitches[7] = { C, D, E, F, G, A, B };
			Tonality tones[7] = { neutral, neutral, flat, neutral, neutral, flat, flat };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4});
			}

			break;
		}
		case sharp:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Minor;

			Pitch pitches[7] = { C, D, E, F, G, A, B };
			Tonality tones[7] = { sharp, sharp, neutral , sharp, sharp, neutral, neutral };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4});
			}

			break;
		}
		default:
			break;
		}
		break;
	case D:
		switch (tone)
		{
		case flat:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Minor;

			Pitch pitches[7] = { D, E, F, G, A, B, C };
			Tonality tones[7] = { flat, flat, flat, flat, flat, doubleFlat, flat };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		case neutral:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Minor;

			Pitch pitches[7] = { D, E, F, G, A, B, C };
			Tonality tones[7] = { neutral, neutral, neutral, neutral, neutral, flat, neutral };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		case sharp:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Minor;

			Pitch pitches[7] = { D, E, F, G, A, B, C };
			Tonality tones[7] = { sharp, sharp, sharp, sharp, sharp, neutral, sharp };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		default:
			break;
		}
		break;
	case E:
		switch (tone)
		{
		case flat:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Minor;

			Pitch pitches[7] = { E, F, G, A, B, C, D };
			Tonality tones[7] = { flat, neutral, flat, flat, flat, flat, flat };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		case neutral:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Minor;

			Pitch pitches[7] = { E, F, G, A, B, C, D };
			Tonality tones[7] = { neutral, sharp, neutral, neutral, neutral, neutral, neutral };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		case sharp:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Minor;

			Pitch pitches[7] = { E, F, G, A, B, C, D };
			Tonality tones[7] = { sharp, doubleSharp, sharp, sharp, sharp, sharp, sharp };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		default:
			break;
		}
		break;
	case F:
		switch (tone)
		{
		case flat:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Minor;

			Pitch pitches[7] = { F, G, A, B, C, D, E };
			Tonality tones[7] = { flat, flat, doubleFlat, doubleFlat, flat, doubleFlat, doubleFlat };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		case neutral:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Minor;

			Pitch pitches[7] = { F, G, A, B, C, D, E };
			Tonality tones[7] = { neutral, neutral, flat, flat, neutral, flat, flat };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		case sharp:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Minor;

			Pitch pitches[7] = { F, G, A, B, C, D, E };
			Tonality tones[7] = { sharp, sharp, neutral, neutral, sharp, neutral, neutral };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		default:
			break;
		}
		break;
	case G:
		switch (tone)
		{
		case flat:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Minor;

			Pitch pitches[7] = { G, A, B, C, D, E, F };
			Tonality tones[7] = { flat, flat, doubleFlat, flat, flat, doubleFlat, flat };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		case neutral:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Minor;

			Pitch pitches[7] = { G, A, B, C, D, E, F };
			Tonality tones[7] = { neutral, neutral, flat, neutral, neutral, flat, neutral };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		case sharp:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Minor;

			Pitch pitches[7] = { G, A, B, C, D, E, F };
			Tonality tones[7] = { sharp, sharp, neutral, sharp, sharp, neutral, sharp };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		default:
			break;
		}
		break;
	case A:
		switch (tone)
		{
		case flat:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Minor;

			Pitch pitches[7] = { A, B, C, D, E, F, G };
			Tonality tones[7] = { flat, flat, flat, flat, flat, flat, flat };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		case neutral:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Minor;

			Pitch pitches[7] = { A, B, C, D, E, F, G };
			Tonality tones[7] = { neutral, neutral, neutral, neutral, neutral, neutral, neutral };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		case sharp:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Minor;

			Pitch pitches[7] = { A, B, C, D, E, F, G };
			Tonality tones[7] = { sharp, sharp, sharp, sharp, sharp, sharp, sharp };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		default:
			break;
		}
		break;
	case B:
		switch (tone)
		{
		case flat:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Minor;

			Pitch pitches[7] = { B, C, D, E, F, G, A };
			Tonality tones[7] = { flat, neutral, flat, flat, neutral, flat, flat };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		case neutral:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Minor;

			Pitch pitches[7] = { B, C, D, E, F, G, A };
			Tonality tones[7] = { neutral, sharp, neutral, neutral, sharp, neutral, neutral };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		case sharp:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Minor;

			Pitch pitches[7] = { B, C, D, E, F, G, A };
			Tonality tones[7] = { sharp, doubleSharp, sharp, sharp, doubleSharp, sharp, sharp };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void Scale::makeMixolydianScale(Pitch pitch, Tonality tone)
{
	switch (pitch)
	{
	case C:
		switch (tone)
		{
		case flat:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Mixolydian;

			Pitch pitches[7] = { C, D, E, F, G, A, B };
			Tonality tones[7] = { flat, flat, flat, flat, flat, flat, doubleFlat };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		case neutral:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Mixolydian;

			Pitch pitches[7] = { C, D, E, F, G, A, B };
			Tonality tones[7] = { neutral, neutral, neutral, neutral, neutral, neutral, flat };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		case sharp:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Mixolydian;

			Pitch pitches[7] = { C, D, E, F, G, A, B };
			Tonality tones[7] = { sharp, sharp, sharp , sharp, sharp, sharp, neutral };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		default:
			break;
		}
		break;
	case D:
		switch (tone)
		{
		case flat:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Mixolydian;

			Pitch pitches[7] = { D, E, F, G, A, B, C };
			Tonality tones[7] = { flat, flat, neutral, flat, flat, flat, flat };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		case neutral:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Mixolydian;

			Pitch pitches[7] = { D, E, F, G, A, B, C };
			Tonality tones[7] = { neutral, neutral, sharp, neutral, neutral, neutral , neutral };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		case sharp:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Mixolydian;

			Pitch pitches[7] = { D, E, F, G, A, B, C };
			Tonality tones[7] = { sharp, sharp, doubleSharp, sharp, sharp, sharp, sharp };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		default:
			break;
		}
		break;
	case E:
		switch (tone)
		{
		case flat:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Mixolydian;

			Pitch pitches[7] = { E, F, G, A, B, C, D };
			Tonality tones[7] = { flat, neutral, neutral, flat, flat, neutral, flat };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		case neutral:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Mixolydian;

			Pitch pitches[7] = { E, F, G, A, B, C, D };
			Tonality tones[7] = { neutral, sharp, sharp, neutral, neutral, sharp, neutral };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		case sharp:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Mixolydian;

			Pitch pitches[7] = { E, F, G, A, B, C, D };
			Tonality tones[7] = { sharp, doubleSharp, doubleSharp, sharp, sharp, doubleSharp, sharp };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		default:
			break;
		}
		break;
	case F:
		switch (tone)
		{
		case flat:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Mixolydian;

			Pitch pitches[7] = { F, G, A, B, C, D, E };
			Tonality tones[7] = { flat, flat, flat, doubleFlat, flat, flat, doubleFlat };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		case neutral:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Mixolydian;

			Pitch pitches[7] = { F, G, A, B, C, D, E };
			Tonality tones[7] = { neutral, neutral, neutral, flat, neutral, neutral, flat };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		case sharp:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Mixolydian;

			Pitch pitches[7] = { F, G, A, B, C, D, E };
			Tonality tones[7] = { sharp, sharp, sharp, neutral, sharp, sharp, neutral };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		default:
			break;
		}
		break;
	case G:
		switch (tone)
		{
		case flat:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Mixolydian;

			Pitch pitches[7] = { G, A, B, C, D, E, F };
			Tonality tones[7] = { flat, flat, flat, flat, flat, flat, flat };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		case neutral:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Mixolydian;

			Pitch pitches[7] = { G, A, B, C, D, E, F };
			Tonality tones[7] = { neutral, neutral, neutral, neutral, neutral, neutral, neutral };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		case sharp:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Mixolydian;

			Pitch pitches[7] = { G, A, B, C, D, E, F };
			Tonality tones[7] = { sharp, sharp, sharp, sharp, sharp, sharp, sharp };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		default:
			break;
		}
		break;
	case A:
		switch (tone)
		{
		case flat:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Mixolydian;

			Pitch pitches[7] = { A, B, C, D, E, F, G };
			Tonality tones[7] = { flat, flat, neutral, flat, flat, neutral, flat };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		case neutral:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Mixolydian;

			Pitch pitches[7] = { A, B, C, D, E, F, G };
			Tonality tones[7] = { neutral, neutral, sharp, neutral, neutral, sharp, neutral };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		case sharp:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Mixolydian;

			Pitch pitches[7] = { A, B, C, D, E, F, G };
			Tonality tones[7] = { sharp, sharp, doubleSharp, sharp, sharp, doubleSharp, sharp };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		default:
			break;
		}
		break;
	case B:
		switch (tone)
		{
		case flat:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Mixolydian;

			Pitch pitches[7] = { B, C, D, E, F, G, A };
			Tonality tones[7] = { flat, neutral, neutral, flat, neutral, neutral, flat };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		case neutral:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Mixolydian;

			Pitch pitches[7] = { B, C, D, E, F, G, A };
			Tonality tones[7] = { neutral, sharp, sharp, neutral, sharp, sharp, neutral };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		case sharp:
		{
			_pitch = pitch;
			_tone = tone;
			_type = Mixolydian;

			Pitch pitches[7] = { B, C, D, E, F, G, A };
			Tonality tones[7] = { sharp, doubleSharp, doubleSharp, sharp, doubleSharp, doubleSharp, sharp };

			for (size_t i = 0; i < 7; i++)
			{
				_notes[i] = Note(NoteInfo{ pitches[i], tones[i], quarter, 4 });
			}

			break;
		}
		default:
			break;
		}
		break;
	default:
		break;
	}
}

Note Scale::GetFirst()
{
	return _notes[0];
}

Note Scale::GetSecond()
{
	return _notes[1];
}

Note Scale::GetThird()
{
	return _notes[2];
}

Note Scale::GetFourth()
{
	return _notes[3];
}

Note Scale::GetFifth()
{
	return _notes[4];
}

Note Scale::GetSixth()
{
	return _notes[5];
}

Note Scale::GetSeventh()
{
	return _notes[6];
}

Note Scale::GetRest() {
	return Note(NoteInfo { REST, neutral, quarter, 4 });
}

Note Scale::GetErr() {
	return Note(NoteInfo{ PitchErr, neutral, quarter, 4 });
}