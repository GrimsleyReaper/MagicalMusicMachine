#pragma once

enum Pitch
{
	PitchErr = -2,
	REST = -1,
	C = 1,
	D = 2,
	E = 4,
	F = 8,
	G = 16,
	A = 32,
	B = 64
};

enum Tonality
{
	doubleFlat = -1,
	flat = 1,
	neutral = 2,
	sharp = 4,
	doubleSharp = 8
};

enum Length
{
	LengthErr = -1,
	whole = 1,
	half = 2,
	quarter = 4,
	eigth = 8,
	sixteenth = 16,
	thirtysecond = 32
};

enum ScaleType
{
	Major = 0,
	Minor = 1,
	Mixolydian = 4
};

enum TimeState
{
	tooShort = -1,
	tooLong = 0,
	perfect = 1
};