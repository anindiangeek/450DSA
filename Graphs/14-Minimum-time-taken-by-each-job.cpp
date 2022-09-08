#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> minimumTime(int n, vector<vector<int>> &edges, int m)
    {
        vector<int> distance(n + 1, -INFINITY);
        vector<int> Indegree(n + 1, 0);
        vector<int> adj[n + 1];
        queue<int> q;

        for (auto x : edges)
        {
            adj[x[0]].push_back(x[1]);
            Indegree[x[1]]++;
        }

        for (int i = 1; i <= n; i++)
            if (!Indegree[i])
            {
                q.push(i);
                distance[i] = 1;
            }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto x : adj[node])
            {
                if (distance[node] + 1 > distance[x])
                    distance[x] = distance[node] + 1;

                Indegree[x]--;
                if (Indegree[x] == 0)
                    q.push(x);
            }
        }
        distance.erase(distance.begin());
        return distance;
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
        int m;
        cin >> m;
        vector<vector<int>> edges(m, vector<int>(2));
        for (int i = 0; i < m; i++)
            cin >> edges[i][0] >> edges[i][1];
        Solution s;
        vector<int> ans = s.minimumTime(n, edges, m);
        for (auto j : ans)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}