#include "BarOptions.h"

void BarOptions::ConvertToEnums()
{
    switch (pitch)
    {
    case 0:
        ePitch = C;
        break;
    case 1:
        ePitch = D;
        break;
    case 2:
        ePitch = E;
        break;
    case 3:
        ePitch = F;
        break;
    case 4:
        ePitch = G;
        break;
    case 5:
        ePitch = A;
        break;
    case 6:
        ePitch = B;
        break;
    default:
        ePitch = C;
        break;
    }

    switch (tone)
    {
    case 0:
        eTone = flat;
        break;
    case 1:
        eTone = neutral;
        break;
    case 2:
        eTone = sharp;
        break;
    default:
        eTone = neutral;
        break;
    }

    switch (scaleType)
    {
    case 0:
        eScaleType = Major;
        break;
    case 1:
        eScaleType = Minor;
        break;
    case 2:
        eScaleType = Mixolydian;
        break;
    default:
        eScaleType = Major;
        break;
    }

    int top = -1;
    int bottom = -1;

    switch (timeTop)
    {
    case 0:
        top = 2;
        break;
    case 1:
        top = 3;
        break;
    case 2:
        top = 4;
        break;
    case 3:
        top = 7;
        break;
    case 4:
        top = 8;
        break;
    case 5:
        top = 12;
        break;
    default:
        break;
    }

    switch (timeBottom)
    {
    case 0:
        bottom = 2;
        break;
    case 1:
        bottom = 4;
        break;
    case 2:
        bottom = 8;
        break;
    default:
        break;
    }

    if (top != -1) {
        timeSignature._top = top;
    }

    if (bottom != -1) {
        timeSignature._bottom = bottom;
    }

    eScale = Scale(ePitch, eTone, eScaleType);
}