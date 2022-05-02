/*
    Problem: Given two numbers x and y, and a range [l, r] where 1 <= l, r <= 32. The task is consider set bits of y in
       range [l, r] and set these bits in x also.

    Input  : x = 10, y = 13, l = 2, r = 3
    Output : x = 14
    Binary representation of 10 is 1010 and
    that of y is 1101. There is one set bit
    in y at 3'rd position (in given range).
    After we copy this bit to x, x becomes 1110
    which is binary representation of 14.

    Problem Links : NA

    Solution / Explanation : https://www.geeksforgeeks.org/copy-set-bits-in-a-range/

*/

#include <bits/stdc++.h>
using namespace std;

class Solution1 // O(r)
{
  public:
    void copySetBits(unsigned &x, unsigned y, unsigned l, unsigned r)
    {
        // l and r must be between 1 to 32
        // (assuming ints are stored using
        //  32 bits)
        if (l < 1 || r > 32)
            return;

        // Traverse in given range
        for (int i = l; i <= r; i++)
        {
            // Find a mask (A number whose
            // only set bit is at i'th position)
            int mask = 1 << (i - 1);

            // If i'th bit is set in y, set i'th
            // bit in x also.
            if (y & mask)
                x = x | mask;
        }
    }
};
class Solution2 // O(r)
{
  public:
    void copySetBits(unsigned &x, unsigned y, unsigned l, unsigned r)
    {
        if (l < 1 || r > 32)
            return;

        // get the length of the mask
        int maskLength = (1ll << (r - l + 1)) - 1;

        // Shift the mask to the required position
        // "&" with y to get the set bits at between
        // l ad r in y
        int mask = ((maskLength) << (l - 1)) & y;
        x = x | mask;
    }
};

int main()
{
}