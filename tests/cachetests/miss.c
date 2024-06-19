//========================================================================//
// miss.c: test that the cpu accesses non-cached elements correctly.      //
// The verification is done by checking the hit output of the cache       //
// module inside the testbench.                                           //                         
//========================================================================//
#include <stdio.h>  
#define CACHE_SIZE 1024
#define LINE_SIZE 64
#define INT_SIZE 4
#define STRIDE 16

void main()
{
    int index;
    int arr[CACHE_SIZE];
    for (int j = 0; j < LINE_SIZE; j ++)
    {
        index = 1;
        arr[index]++;
    }
}