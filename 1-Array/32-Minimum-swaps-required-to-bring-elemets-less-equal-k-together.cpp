/*
 * https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1

    Solution : https://www.geeksforgeeks.org/minimum-swaps-required-bring-elements-less-equal-k-together/

 */

#include <bits/stdc++.h>
using namespace std;

class NaiveSolution // O(N^2)
{
    int minSwap(int arr[], int n, int k)
    {
        int Count = 0; // count of elements less than or equal to k
        for (int i = 0; i < n; i++)
            if (arr[i] <= k)
                Count++;

        // iterate through a;; the possible subarry and check the elements to remove from that array.
        int answer = INT_MAX;
        for (int start = 0; start <= n - Count; start++)
        {
            int ElementsGreaterThanK = 0;

            for (int i = start; i < start + Count; i++)
                if (arr[i] > k)
                    ElementsGreaterThanK++;

            answer = min(answer, ElementsGreaterThanK);
        }
        return answer;
    }
};

class Solution // O(N) //S(1)
{
  public:
    int minSwap(int arr[], int n, int k)
    {
        int Count = 0; // count of elements less than or equal to k
        for (int i = 0; i < n; i++)
            if (arr[i] <= k)
                Count++;

        // Calculating the elements in the current "count" sized window which are not suppossed to be there.
        int answer = 0, bad = 0;
        for (int i = 0; i < Count; i++)
            if (arr[i] > k)
                bad++;

        answer = bad;

        // using slilding window technique;
        for (int i = 0, j = Count; j < n; i++, j++)
        {
            // if the current element that left the window was bad element
            if (arr[i] > k)
                --bad;

            if (arr[j] > k)
                ++bad;

            answer = min(answer, bad);
        }
        return answer;
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

    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cin >> k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
    return 0;
}