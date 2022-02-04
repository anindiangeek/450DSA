/*
    https://leetcode.com/problems/next-permutation/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int i = n - 1;
        if (is_sorted(nums.rbegin(), nums.rend()))
        {
            sort(nums.begin(), nums.end());
            return;
        }

        if (n == 1)
            return;
        while (i > 0 && nums[i] <= nums[i - 1])
            --i;

        int min_idx = i;
        int pick = nums[i - 1];
        for (int j = i; j < n; j++)
            if (nums[j] < nums[min_idx] && nums[j] > pick)
                min_idx = j;
        assert(i - 1 >= 0);
        swap(nums[i - 1], nums[min_idx]);

        sort(nums.begin() + i, nums.end());
    }
};