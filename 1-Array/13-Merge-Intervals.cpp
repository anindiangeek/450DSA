#include <bits/stdc++.h>
using namespace std;
/*
    https://leetcode.com/problems/merge-intervals/
*/
class Solution
{
  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        for (vector<int> x : intervals)
        {
            if (ans.back()[1] >= x[0])
                ans.back()[1] = max(ans.back()[1], x[1]);
            else
                ans.push_back(x);
        }
        return ans;
    }
};
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
vector<vector<int>> intervals(4, vector<int>(2));
#ifndef ONLINE_JUDGE
    freopen("i.txt", "r", stdin);
    freopen("e.txt", "w+", stderr);
#endif
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 2; j++)
            cin >> intervals[i][j];
    Solution ob;
    ob.merge(intervals);
    for (vector<int> x : intervals)
        cerr << x[0] << " " << x[1] << endl;
    cerr << endl;
}