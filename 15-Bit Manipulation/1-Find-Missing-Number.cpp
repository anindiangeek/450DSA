/*
    Problem : Given a array of size 2 * n + 2 find two elements that are not repeating.
    T.C => O(n) S(1)

    Concept : Properties of XOR ^ operaotr

    Problem Links :

    https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1# (medium)
    https://codeforces.com/group/yg7WhsFsAp/contest/355504/problem/P51 (easy)

    Solution & Explanation :
    https://www.geeksforgeeks.org/find-two-non-repeating-elements-in-an-array-of-repeating-elements/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    /*
        a ^ a = 0
        a ^ 0 = a
        when we xor the complete array we get the non repeating number, or XOR of non repeating numbers.
    */
  public:
    vector<int> singleNumber(vector<int> nums)
    {
        if (!nums.size())
            return {};

        int WholeXOR = nums[0];

        for (int i = 1; i < nums.size(); i++)
            WholeXOR ^= nums[i];

        int x = 0, y = 0;

        int Mask = WholeXOR & ~(WholeXOR - 1);

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] & Mask)
                x ^= nums[i];
            else
                y ^= nums[i];
        }

        return {min(x, y), max(x, y)};
    }
};

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> v(2 * n + 2);
        for (int i = 0; i < 2 * n + 2; i++)
            cin >> v[i];
        Solution ob;
        vector<int> ans = ob.singleNumber(v);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}