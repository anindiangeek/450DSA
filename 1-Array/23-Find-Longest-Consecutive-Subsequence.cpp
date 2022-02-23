/*
    * https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1

    Explanation : https://www.youtube.com/watch?v=qgizvmgeyUM
*/

#include <bits/stdc++.h>
using namespace std;

// The main idea is to find the minimum element of the sequence and then count++
// Then store the length of the maximum size subarray

class SolutionUsingHasing // O(N) & S(N)
{
public:
    int findLongestConseqSubseq(int arr[], int n)
    {
        unordered_set<int> hash;
        int answer = 0;

        for (int i = 0; i < n; i++)
            hash.insert(arr[i]);

        for (int i = 0; i < n; i++)
        {
            int count = 0;

            //Checking if this is the start of any subsequence & counting the elements including itself

            if (hash.find(arr[i] - 1) == hash.end())
                for (int j = arr[i]; hash.find(j) != hash.end(); j++)
                    count++;

            answer = max(count, answer);
        }

        return answer;
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