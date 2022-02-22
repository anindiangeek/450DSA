/*
    https://leetcode.com/problems/find-the-duplicate-number/solution/

*/

#include <bits/stdc++.h>
using namespace std;

class NaiveApproach
{

    // We will sort the array and then we can just compare the adjacent elements and return the duplicate number

public:
    int findDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == nums[i + 1])
                return nums[i];
        }
        return -1;
    }
};

class FloydAlgorithm // O(n) & S(1);
{
    // cycle detection. https://en.wikipedia.org/wiki/Cycle_detection#Tortoise_and_hare
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = nums[0], fast = nums[0];
        // first phase of flyod's algorithm.
        // finding intersection.
        do
        {
            // moving single step.
            slow = nums[slow];
            // moving two steps.
            fast = nums[nums[fast]];
        } while (slow != fast);

        // second phase of flyod's algorithm.
        fast = nums[0];
        while (fast != slow)
        {
            slow = nums[slow];
            fast = nums[fast];
            // they will meet at starting of loop.
        }
        return fast;
    }
};

class NegativeMarkingSolution // O(n) & S(1)
{
    /*
        Since the numbers are [1:N], so we use the array indices for storing the
        visited state of each number, only the duplicate will be visited twice.
        For each number we goto its index position and multiply by -1. In case
        of duplicate it will be multiplied twice and the number will be +ve.
      */

public:
    int findDuplicate(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            int index = abs(nums[i]) - 1;

            // mark as visited

            nums[index] *= -1;

            // incase of duplicate, this will become +ve

            if (nums[index] > 0)
                return abs(nums[i]);
        }
        return -1;
    }
};

void solve()
{
    vector<int> nums = {1, 2, 4, 4, 3};
    NaiveApproach O1;
    cout << O1.findDuplicate(nums);
}

int main()
{

    int T = 1;
    // cin >> T;
    while (T--)
        solve();
}

/* Written by : Utkarsh Mishra */