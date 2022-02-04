/*
    https://leetcode.com/problems/find-the-duplicate-number/solution/

*/

#include <bits/stdc++.h>
using namespace std;
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
    // as the numbers are from 1-n only.
    // we will flip the ith postion number sign
    // if that number is alrady filled then that is the duplicate element;
  public:
    int findDuplicate(vector<int> &nums)
    {
        int duplicate = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            int curr = abs(nums[i]);
            if (nums[curr] < 0)
            {
                duplicate = curr;
                break;
            }
            nums[curr] *= -1;
        }
        // we can also restore the original array
        // by taking mod of all the values in it.
        /*
            for(auto& num : nums)
                num = abs(num);
        */
        return duplicate;
    }
};

void solve()
{
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("i.txt", "r", stdin);
    freopen("e.txt", "w+", stderr);
#endif
    int T = 1;
    cin >> T;
    while (T--)
        solve();
}

/* Written by : Utkarsh Mishra */