//========================================================================//
// full.c: test that elements fall inside the correct sets and blocks     //
// inside the cache. Verification file: ../results/full.txt               //
//========================================================================//
#include <stdio.h>  
#include "constants.h"

void main()
{
    int index;
    int a[NUM_ELEMENTS];
    for (int i = 0; i < NUM_ELEMENTS; i++) //attention! i also in cache
    {
        a[i] = i;
    }
    SET_END_MARKER();
}