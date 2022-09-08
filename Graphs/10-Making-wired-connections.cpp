/*
    * https://leetcode.com/problems/number-of-operations-to-make-network-connected/

    *
    *
    *


*/
#include <bits/stdc++.h>
using namespace std;

class BFSSolution
{
public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        int edge = connections.size();
        if (edge < n - 1)
            return -1;

        vector<int> adj[n];

        for (auto val : connections)
        {
            adj[val[0]].push_back(val[1]);
            adj[val[1]].push_back(val[0]);
        }

        int wires = 1;
        vector<int> visited(n, 0);
        queue<int> q;
        q.push(0);
        while()
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(adj, visited, i);
                wires++;
            }
        }
        return wires - 1;
    }
};

class DFSSolution
{
public:
    void dfs(vector<int> adj[], vector<int> &visited, int node)
    {
        visited[node] = 1;

        for (auto x : adj[node])
            if (!visited[x])
                dfs(adj, visited, x);
    }

    int makeConnected(int n, vector<vector<int>> &connections)
    {
        vector<int> adj[n];
        for (auto val : connections)
            adj[val[0]].push_back(val[1]);

        int edge = connections.size();
        if (edge < n - 1)
            return -1;

        int wires = 1;
        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(adj, visited, i);
                wires++;
            }
        }
        return wires - 1;
    }
};