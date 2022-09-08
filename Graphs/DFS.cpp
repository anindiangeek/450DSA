//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool CheckForCycle(int Node, int Parent, vector<int> &vis, vector<int> adj[])
    {
        vis[Node] = 1;
        for (auto x : adj[Node])
        {
            if (!vis[x])
                if (CheckForCycle(x, Node, vis, adj))
                    return true;
            else if (x != Parent)
                    return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (CheckForCycle(i, -1, vis, adj))
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends