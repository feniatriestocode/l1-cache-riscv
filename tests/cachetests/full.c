//========================================================================//
// full.c: test that elements fall inside the correct sets and blocks     //
// inside the cache. Verification file: ../results/full.txt               //
//========================================================================//
#include <stdio.h>  
#define NUM_ELEMENTS 1024

void main()
{
    int index;
    int a[NUM_ELEMENTS] = 0;
    int b[NUM_ELEMENTS] = 0;
    for (int i = 0; i < NUM_ELEMENTS; i++)
    {
        a[i]++;
        b[i] = a[i]--;
    }
}