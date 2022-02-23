#include <bits/stdc++.h>
using namespace std;

/*
    the best explanation for all these methods.
    https://www.youtube.com/watch?v=ohHWQf1HDfU

    there is one more method that is by using prefix sum.
    https://www.geeksforgeeks.org/maximum-subarray-sum-using-prefix-sum/
    but T.C O(n) & S(n)

*/

class ImprovedKadandeAlgorithm
{
public:
    int MSS(vector<int> &nums)
    {
       //In this method we don't have to count the number of negative values as it already takes the maximum possible negative value present in the array
        
        int maxendinghere = 0, sum = INT_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            maxendinghere += nums[i];

            if (sum < maxendinghere)
                sum = maxendinghere;

            if (maxendinghere < 0)
                maxendinghere = 0;
        }

        return sum;
    }
};

class KadaneAlgorithm // O(N) & S(1)
{
    // this algorithm works only when there is atleast one positive number in array.
    // if all the numbers in an array can be negative then we have to check it and return the max number as the answer.
public:
    int64_t MaxSumSubArray(int arr[], int n)
    {
        int64_t sum = 0, NegativeCount = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {

            if (arr[i] < 0)
                NegativeCount++;
            if (sum + arr[i] < 0)
                sum = 0;
            else
                sum += arr[i];
            ans = max(sum, ans);
        }
        return (NegativeCount == n) ? *max_element(arr, arr + n) : ans;
    }
};

class DivideAndConquer // O(NlogN)
{
    /* Recurrance Relation.
        t(n) = {
                c  ;          n=1
                t(n/2) + cn   n>1
               }
    */

public:
    int64_t MSS(int arr[], int n)
    {

        if (n == 1)
            return arr[0];

        int m = n / 2; // half of the array.

        int64_t LeftMSS = MSS(arr, m);
        int64_t RightMSS = MSS(arr + m, n - m);

        int64_t LeftSum = INT64_MIN, RightSum = INT64_MIN, sum = 0;

        for (int i = m - 1; i >= 0; --i)
        {
            sum += arr[i];
            LeftSum = max(LeftSum, sum);
        }

        sum = 0;

        for (int i = m; i < n; i++)
        {
            sum += arr[i];
            RightSum = max(RightSum, sum);
        }

        int64_t ans = max(LeftMSS, RightMSS);

        return max(ans, LeftSum + RightSum);
    }
};

class BetterNaiveSolution // O(n^2)
{
public:
    // rather than selecting subarray size first we will select the startindex first and calculate sum by just adding the last element to it

    int64_t maxSubarraySum(int arr[], int n)
    {
        int64_t ans = INT64_MIN;
        for (int StartIndex = 0; StartIndex < n; ++StartIndex)
        {
            int64_t sum = 0;

            for (int SubArraySize = 1; SubArraySize <= n; ++SubArraySize)
            {
                if (StartIndex + SubArraySize > n) // if it is out of bounds break.
                    break;
                sum += arr[StartIndex + SubArraySize - 1];
                ans = max(sum, ans);
                /*
                    // for visualzation of how this works and what is the difference between this and O(N^3) solution
                for (int i = StartIndex; i < StartIndex + SubArraySize; ++i)
                    cerr << arr[i] << " ";
                cerr << endl;
                 */
            }
        }
        return ans;
    }
};

class NaiveSolution // O(N^3)
{
public:
    // if we go through all the subsequences, for n sized array there are n*(n+1)/2 sub-arrays.
    // T.C will be O(n^3)
    // here we are iterating the sub arrays by size first.
    int64_t maxSubarraySum(int arr[], int n)
    {
        int64_t ans = INT64_MIN;
        for (int SubArraySize = 1; SubArraySize <= n; ++SubArraySize)
        {
            for (int StartIndex = 0; StartIndex < n; ++StartIndex)
            {
                if (StartIndex + SubArraySize > n) // check if we do no get out of bounds.
                    break;
                int64_t sum = 0;
                for (int i = StartIndex; i < StartIndex + SubArraySize; ++i)
                    sum += arr[i];
                ans = max(sum, ans);
            }
        }
        return ans;
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("i.txt", "r", stdin);
    freopen("e.txt", "w+", stderr);
#endif
    int t, n;

    cin >> t;
    while (t--)
    {

        cin >> n;

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        NaiveSolution ON3;
        BetterNaiveSolution ON2;
        DivideAndConquer ONLOGN;
        KadaneAlgorithm ON;
        cout << ONLOGN.MSS(a, n) << endl;
        cout << ON.MaxSumSubArray(a, n) << endl;
    }
}