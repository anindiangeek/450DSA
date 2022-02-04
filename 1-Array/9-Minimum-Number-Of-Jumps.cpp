/*
    https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1#


    https://www.youtube.com/watch?v=hZkb_Dqu7YY

    you cannot inint al the values of an array int a[]={} like this to a non-zero value, it will do for only first
   index.
*/

#include <bits/stdc++.h>
using namespace std;

class GreedySolution // O(N) & S(1)
{
    // most effecient solution to this problem.
  public:
    int minJumps(int arr[], int size)
    {
        if (size < 2) // nowhere to go
            return 0;

        if (arr[0] == 0) // can't move.
            return -1;

        int MaxIndexReachable = 0; // from any index what is the maximum postion can be reached.
		int limit = 0; // to check if we reach the maximum position.
		int jumps = 0; // the answer.

        for (int i = 0; i < size - 1; i++)
        {
			// for every iteration updating the Maximumreachable position.
            MaxIndexReachable = max(MaxIndexReachable, i + arr[i]);

            if (i == limit)
            {
                jumps++;
                limit = MaxIndexReachable;
            }

            // important check.
            if (arr[i] == 0 && i == limit)
                return -1;
        }
        return jumps;
    }
};

// this can be done using DP and you can easily see this is an optimization problem.
class DPsolution // O(N^2)
{
  public:
    int minJumps(int arr[], int size)
    {

        // dp[size - 1] = 0;
        vector<int> jumps(size, INT_MAX);
        jumps[0] = 0;

        for (int i = 1; i < size; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (i <= (j + arr[j]))
                {
                    jumps[i] = min(jumps[i], 1 + jumps[j]);
                    break;
                }
            }
        }
        return jumps[size - 1];
    }
};

class NaiveApproach // O(N^N)
{
    // we will go through all the possible paths at each steps to determine minimum jumps.

    int decideJumps(int arr[], int size, int pos)
    {
        // base case
        // if we reach or cross the size then jumps will be 0;
        if (pos >= size - 1)
            return 0;

        // you know what is this.
        int MinJumps = INT_MAX;

        // we can take these may steps only.
        int maxSteps = arr[pos];

        while (maxSteps > 0)
        {
            // for each step we are adding our jump to reach that position and then adding
            // jumps from that to next pos where we will reach.
            MinJumps = min(MinJumps, 1 + decideJumps(arr, size, pos + maxSteps));

            // reducing the steps by 1 but why?..
            // because in each step we are moving forward by current_pos + maxSteps
            maxSteps = maxSteps - 1;
        }
        // giving the numebr of jumps.
        return MinJumps;
    }

  public:
    int minJumps(int arr[], int size)
    {
        return decideJumps(arr, size, 0);
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("C://450DSA//i.txt", "r", stdin);
    freopen("C://450DSA//e.txt", "w+", stderr);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        NaiveApproach ONN;
        DPsolution ON2;
        GreedySolution ON;
        cout << ON.minJumps(arr, n) << endl;
    }
    return 0;
}