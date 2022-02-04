/*
	* https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

    * https://www.youtube.com/watch?v=eMSfBgbiEjk
 */

#include <bits/stdc++.h>
using namespace std;

class Solution // O(N) S(1)
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int CurrentMinimumValueFound = INT_MAX; // stores minimal left value.
        int Profit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            CurrentMinimumValueFound = min(prices[i], CurrentMinimumValueFound);
            Profit = max(Profit, prices[i] - CurrentMinimumValueFound);
        }
        return Profit;
    }
};

class BruteForce // O(N^2) S(1)
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int Profit = INT_MIN;

        for (int i = 0; i < prices.size(); ++i)
            for (int j = i + 1; j < prices.size(); ++j)
                Profit = max(Profit, prices[j] - prices[i]);

        Profit = (Profit < 0) ? 0 : Profit;
        return Profit;
    }
};

int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n = 0;
        cin >> n;
        vector<int> prices(n);
        for (int &i : prices)
            cin >> i;

        BruteForce ON2;
        cout << ON2.maxProfit(prices) << endl;
    }
    return 0;
}