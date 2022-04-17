/*
    Problem: Given N, return total number of set bits in every number from 1...N.

    Solution & Explanation :

    * it is very easy to come up with a O(NlogN) solution, for each value count the number of set bits in log2N time.

    * __builtin_popcount  can be used for the same purpose but now C++ 20 has std::__popcount that is preferred and it
   works in O(Number of bits) complexity.
        __builtin_popcount = int
        __builtin_popcountl = long int
        __builtin_popcountll = long long
    https://en.cppreference.com/w/cpp/numeric/popcount
    https://stackoverflow.com/questions/60165922/stdbitsetncount-vs-builtin-popcount

    Other Optimisations are based on observations : this can be done in O(LogN) and O(N){Leetcode}
    * https://www.geeksforgeeks.org/count-total-set-bits-in-all-numbers-from-1-to-n/
    * https://www.geeksforgeeks.org/count-total-set-bits-in-all-numbers-from-1-to-n-set-2/

    Problem Links:
     * https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1
     * https://leetcode.com/problems/counting-bits/

*/

#include <bits/stdc++.h>
using namespace std;

class Solution // O(logN)
{
    /*
        Concept

    Decimal	E	D	C	B	A

        0	0	0	0	0	0
        1	0	0	0	0	1
        2	0	0	0	1	0
        3	0	0	0	1	1
        4	0	0	1	0	0
        5	0	0	1	0	1
        6	0	0	1	1	0
        7	0	0	1	1	1
        8	0	1	0	0	0
        9	0	1	0	0	1
        10	0	1	0	1	0
        11	0	1	0	1	1
        12	0	1	1	0	0
        13	0	1	1	0	1
        14	0	1	1	1	0
        15	0	1	1	1	1
        16	1	0	0	0	0

    * from observation we can see that A has set bit alteranting, B after 2, C after 4.
        2^0 2^1.... let's call this current section.

        as this is starting from 0, we will add 1 to the number.
    */
  public:
    int countSetBits(int n)
    {
        n = n + 1;
        int CurrentSection{2}; // E D C B A

        // we already know the answer of A is n/2.

        int SetBits = n / 2;

        while (CurrentSection <= n)
        {
            // total number of pairs of 0 & 1 in this section.
            int Pairs = n / CurrentSection;

            SetBits += (Pairs / 2) * CurrentSection; // set pairs * power of 2.

            SetBits += (Pairs & 1) ? (n % CurrentSection) : 0; // if there were odd pairs

            CurrentSection <<= 1; // changing section. i.e multiplying it by 2^1.
        }

        return SetBits;
    }
};

int main()
{
    int t;
    cin >> t;   // input testcases
    while (t--) // while testcases exist
    {
        int n;
        cin >> n; // input n
        Solution ob;
        cout << ob.countSetBits(n) << endl; // print the answer
    }
    return 0;
}