/*
    * https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1

    Explanation : https://www.youtube.com/watch?v=qgizvmgeyUM
*/

#include <bits/stdc++.h>
using namespace std;

class SolutionUsingHasing // O(N) & S(N)
{
  public:
    int findLongestConseqSubseq(int arr[], int N)
    {
        int Answer = 0;
        unordered_set<int> Hash;
        for (int i = 0; i < N; i++) // O(N)
            Hash.insert(arr[i]);

        for (int i = 0; i < N; i++)
        {
            int count = 0;
            if (Hash.find(arr[i] - 1) != Hash.end())
                continue;
            else
                for (int x = arr[i]; Hash.find(x) != Hash.end(); x++)
                    ++count;
            Answer = max(count, Answer);
        }
        return Answer + 1;
    }
};

class NaiveSolution // O(NLogN)
{
  public:
    int findLongestConseqSubseq(int arr[], int N)
    {
        int ans = 0, res = 0;
        sort(arr, arr + N);
        for (int i = 0; i < N - 1; i++)
        {
            // to handle multiple values.
            if (arr[i + 1] == arr[i])
                continue;

            if (arr[i + 1] - arr[i] == 1)
                res++;
            else
                res = 0;

            ans = max(ans, res);
        }
        return ans + 1;
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
    int t, n, i, a[100001];
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> a[i];
        NaiveSolution ONLOGN;
        SolutionUsingHasing ON;

        // cout << ON.findLongestConseqSubseq(a, n) << endl;
        cout << ONLOGN.findLongestConseqSubseq(a, n) << endl;
    }
}