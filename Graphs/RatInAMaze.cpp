#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> ans;
    int x[4] = {0, 0, 1, -1};
    int y[4] = {1, -1, 0, 0};
    char pos[4] = {'R', 'L', 'U', 'D'};
    void dfs(int p, int q, vector<vector<int>> &v, vector<vector<int>> &m, string s)
    {
        if (p == m.size() - 1 and q == m.size() - 1)
            ans.push_back(s);

        for (int i = 0; i < 4; i++)
        {
            int newx = p + x[i], newy = q + y[i];
            // (newx,newy)
            if (newx >= 0 and newy >= 0 and newx < m.size() and newy < m[0].size())
            {
                if (!v[newx][newy] and m[newx][newy] == 1)
                {
                    v[newx][newy] = 1;
                    dfs(newx, newy, v, m, s + pos[i]);
                    v[newx][newy] = 0;
                }
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<vector<int>> v(m.size(), vector<int>(n, 0));
        dfs(0, 0, v, m, "");
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}