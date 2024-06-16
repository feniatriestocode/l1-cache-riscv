//========================================================================//
// hit.c: test that the cpu accesses the cached element correctly.        //
// The verification is done by checking the hit output of the cache       //
// module inside the testbench.                                           //                         
//========================================================================//
void main()
{
    int i = 0;
    while (i < 100000)
    {
       i++;
    }
}