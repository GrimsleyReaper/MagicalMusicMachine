#pragma once

#include "../Enums/Enums.h"
#include "../Entities/Scale.h"

struct TimeSignature
{
    int _top = 4;
    int _bottom = 4;
};

class BarOptions
{
public:
    int pitch = -1;
    int tone = -1;
    int scaleType = -1;
    int timeTop = -1;
    int timeBottom = -1;
    int octave = 1;
    int octaves = 1;

    Pitch ePitch;
    Tonality eTone;
    ScaleType eScaleType;
    TimeSignature timeSignature;
    Scale eScale;

    BarOptions() = default;

    void ConvertToEnums();

};