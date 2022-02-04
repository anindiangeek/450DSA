/*
 * https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1
 * https://leetcode.com/problems/two-sum/
 */

#include <bits/stdc++.h>
using namespace std;

class LeetCodeSolution
{
  public:
    // here we had to return indicies of pairs.
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> M;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = M.find(target - nums[i]);
            if (it != M.end())
                return {i, it->second};
            M[nums[i]] = i;
        }
        return {};
    }
};

class Solution
{
  public:
    int getPairsCount(int arr[], int n, int k)
    {
        unordered_map<int, int> s;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (s.find(k - arr[i]) != s.end())
                count += s[k - arr[i]];

            s[arr[i]]++;
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
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
}