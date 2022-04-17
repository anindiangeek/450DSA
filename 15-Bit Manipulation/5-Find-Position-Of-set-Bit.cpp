/*
    Problem : Given a number N, containing 1 set bit, find it's postion from LSB starting with index 1. if there are
   none or more than 1 set bits are there then return -1;

    Concept : A number has 1 set bit iff it is a power of 2. we can check that in constant time
    Problem Link : https://practice.geeksforgeeks.org/problems/find-position-of-set-bit3706/1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution // O(64)
{
  public:
    int findPosition(int N)
    {
        if (!(N && !(N & (N - 1)))) // refer check if the number is power of 2 question in Bit Manipulation.
            return -1;

        unsigned int i = 1, index = 1;

        while (!(N & i))
        {
            i = i << 1;
            ++index;
        }
    }
};

class BruteForce
{
  public:
    /*
        * The idea is to one by one right shift the set bit of given number ‘n’ until ‘n’ becomes 0.
        Count how many times we shifted to make ‘n’ zero.
         The final count is the position of the set bit.
    */
    int findPosition(int N)
    {
        if (!(N && !(N & (N - 1)))) // refer check if the number is power of 2 question in Bit Manipulation.
            return -1;
        int count = 0;
        while (N)
        {
            N = N >> 1;
            count++;
        }
        return count;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;

        cin >> N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}