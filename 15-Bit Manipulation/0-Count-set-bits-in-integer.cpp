/*
    Problem : Given a Number, count the number of set bits.


    Concept : Brain Kernighan Algorithm // O(log2N)

    * the main idea behind this algorithm is that when we subtract 1 from any number,
    it inverts all the bits after the rightmost set bit i.e. it turns 1 to 0 and 0 to 1.

    Helpful Links
    * https://www.youtube.com/watch?v=e0sVe4-JJJI
    * https://iq.opengenus.org/brian-kernighan-algorithm/#:~:text=The%20main%20idea%20behind%20this,binary%20representation%20of%20these%20numbers.

    Problem Link
    * https://practice.geeksforgeeks.org/problems/set-bits0143/1 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int setBits(int N)
    {
        int ans = 1;
        while (N && ans++)
            N = N & N - 1;
        return ans - 1;
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
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}
