/*
	 * https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1

	Explanation:

 	* https://www.youtube.com/watch?v=lXVy6YWFcRM
*/
#include <bits/stdc++.h>
using namespace std;

class Solution // O(N) S(1)
{
  public:
    long long maxProduct(vector<int> &arr, int n)
    {
        int64_t Answer = *max_element(arr.begin(), arr.end()); // best default case for ex [-6].
        int64_t CurrentMaximum = 1, CurrentMinimum = 1;

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == 0)
            {
                CurrentMaximum = CurrentMinimum = 1;
                continue;
            }

            int64_t temp = CurrentMaximum * arr[i];

            CurrentMaximum = max(CurrentMaximum * arr[i], CurrentMinimum * arr[i]);
            CurrentMaximum = max(CurrentMaximum, (int64_t)arr[i]);

            CurrentMinimum = min(temp, CurrentMinimum * arr[i]);
            CurrentMinimum = min(CurrentMinimum, (int64_t)arr[i]);

            Answer = max(CurrentMaximum, Answer);
        }
        return Answer;
    }
};

class BetterNaiveSolution // O(n^2) S(1)
{
  public:
    int64_t maxProduct(vector<int> arr, int n)
    {
        int64_t Answer = INT64_MIN;
        int size = arr.size();
        for (int StartIndex = 0; StartIndex < size; StartIndex++)
        {
            int64_t Product = 1;
            for (int GroupSize = 1; GroupSize <= size; GroupSize++)
            {
                if (StartIndex + GroupSize > size)
                    break;
                Product = Product * arr[StartIndex + GroupSize - 1];
                Answer = max(Product, Answer);
            }
        }
        return Answer;
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
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++)
            cin >> arr[i];
        BetterNaiveSolution ON2;
        Solution ON;

        auto ans = ON.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}