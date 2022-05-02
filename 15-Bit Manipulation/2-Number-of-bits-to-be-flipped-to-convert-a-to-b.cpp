/*
    Problem : Given two numbers A and B, return number of flips reuqired to convert a to b.

    Problem Link : https://practice.geeksforgeeks.org/problems/bit-difference-1587115620/1/

    Answer & resources :
    https://www.geeksforgeeks.org/count-number-of-bits-to-be-flipped-to-convert-a-to-b/
    https://www.geeksforgeeks.org/count-set-bits-in-an-integer/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b)
    {
        // problem can be reduced to count number of set bits in a number.
        int N = a ^ b;
        // as it is exclusive or so we will get the difference now we just have to count number of set bits.
        // number of set bits in Xor is the answer.
        int count = 0;
        while (N) // using Brian Kernighan’s Algorithm
        {
            N = N & (N - 1);
            count++;
        }
        return count;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--) // while testcases exist
    {
        int a, b;
        cin >> a >> b; // input a and b

        Solution ob;
        cout << ob.countBitsFlip(a, b) << endl;
    }
    return 0;
}