//========================================================================//
// miss.c: test that the cpu accesses non-cached elements correctly.      //
// The verification is done by checking the hit output of the cache       //
// module inside the testbench.                                           //                         
//========================================================================//
#include <stdio.h>  
#include "constants.h"
void main()
{
    int index;
    int arr[STRIDE];
    for (int j = 0; j < STRIDE; j ++) //attention! j also in cache
    {
        index = 1;
        arr[index]++;
    }
}