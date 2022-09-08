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
        int size = nums.size();
        if (size <= 1) // not enough elements
            return;

        int index = size - 1;
        while (index > 0 && nums[index] <= nums[index - 1])
        {
            --index;
            // if the array is in descending order then, there cannot exists a larger permutation.
            // returning next permutation that is sorted elements, we can also return reverse as well.
            if (index <= 0)
            {
                reverse(nums.begin(), nums.end()); // O(N)
                // sort(nums.begin(), nums.end()); // O(NLOGN)
                return;
            }
        }

        int min_idx = index;
        int Element = nums[index - 1];
        // Finding next greater element in [index,last)
        for (int j = index; j < size; j++)
            if (nums[j] < nums[min_idx] && nums[j] > Element)
                min_idx = j;
        // swaping the value of min_idx with the Element.
        swap(nums[index - 1], nums[min_idx]);
        // sorting the rest smaller elements.
        sort(nums.begin() + index, nums.end());
    }
};