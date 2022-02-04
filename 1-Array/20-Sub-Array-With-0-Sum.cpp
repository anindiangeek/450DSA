/*
    https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1#

    unodered sets are used for hashing that finds in almost constant time.

    if there are multiple values(frequencies) then we use unodered_map;

    you can understand why.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    bool subArrayExists(int arr[], int n)
    {
        unordered_set<int> s; // using hasing
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (s.find(sum) != s.end())
                return 1;
            s.insert(arr[i]);
        }
        return 0;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        if (obj.subArrayExists(arr, n))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}