/*
    Q : https://practice.geeksforgeeks.org/problems/topological-sort/1

    * Linear odering of vertices such that if there is an edge u->v,
      u appears before v in that ordering.

      Topo Sort is applicable for DAG : directed acyclic graph.
*/

#include <bits/stdc++.h>
using namespace std;

class BFSSolution // kahn's Algorithm
{
    /*
        Intution : Nodes whose Indegree is less will be first in topological order.
    */
public:
    vector<int> toposort(int V, vector<int> adj[])
    {
        vector<int> Indegree(V, 0);
        vector<int> TopoSort;
        queue<int> q;

        // creating the Indegree Array
        for (int i = 0; i < V; i++)
            for (auto it : adj[i])
                Indegree[it]++;

        // pushing the nodes which have 0 as thier indegree
        for (int i = 0; i < V; i++)
            if (!Indegree[i])
                q.push(i);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            TopoSort.push_back(node);
            for (auto it : adj[node])
            {
                Indegree[it]--;
                if (Indegree[it] == 0)
                    q.push(it);
            }
        }
        return TopoSort;
    }
};

class DFSSolution
{
public:
    vector<int> TopoSortResult;
    void dfs(int node, vector<int> adj[], vector<int> &visited)
    {
        visited[node] = 1;
        TopoSortResult.push_back(node);

        for (auto x : adj[node])
            if (!visited[x])
                dfs(x, adj, visited);
    }

    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> visited(V);

        for (int i = 0; i < V; i++)
            if (!visited[i])
                dfs(i, adj, visited);

        dfs(0, adj, visited);

        reverse(TopoSortResult.begin(), TopoSortResult.end());
        return TopoSortResult;
    }
};

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<int> adj[])
{

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
    {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        DFSSolution obj;
        vector<int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }

    return 0;
}
// } Driver Code Ends