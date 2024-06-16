//========================================================================//
// miss.c: test that the cpu accesses non-cached elements correctly.      //
// The verification is done by checking the hit output of the cache       //
// module inside the testbench.                                           //                         
//========================================================================//
#include <stdio.h>  
#define CACHE_SIZE 1024
#define LINE_SIZE 64
#define INT_SIZE 4
const int stride = LINE_SIZE / INT_SIZE;
void main()
{
    int index;
    int arr[LINE_SIZE * CACHE_SIZE];
    for (int j = 0; j < LINE_SIZE; j ++)
    {
        index = j*stride;
        arr[index]++;
    }
}