/*
    Q : https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/

    H : Learn Prism Algorithm for minimum spanning trees.
*/

#include <bits/stdc++.h>
using namespace std;

class UsingMinHeap // O(ElogV)
{
    /*
        An Important point to note is that if we run a loop till V-1 then this will fail as we wiil still have nodes to be pushed
        in the heap thus resulting in wrong result, we can eaily avoid this by running till our queue is not empty and making things
        same as the naive version.
    */
public:
    int spanningTree(int Nvertex, vector<vector<int>> adj[])
    {
        int answer = 0;
        vector<bool> underMST(Nvertex, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        for (int i = 0; i < Nvertex; i++)
        {
            int node = pq.top().second, weight = pq.top().first;

            while (underMST[node])
                pq.pop();

            pq.pop();

            answer += weight;

            underMST[node] = true;

            for (auto &WeightAndNode : adj[node])
            {
                if (underMST[WeightAndNode[0]])
                    continue;

                pq.push({WeightAndNode[1], WeightAndNode[0]});
            }
        }

        return answer;
    }
};

class NaiveApproach
{
public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<bool> MST(V, false);
        vector<int> KEY(V, INT_MAX);
        vector<int> Parent(V, -1);

        KEY[0] = 0;
        Parent[0] = -1;

        // MST have n-1 edges only
        for (int count = 0; count < V - 1; count++)
        {
            int min = INT_MAX, node;

            for (int i = 0; i < V; i++)
            {
                if (!MST[i] and KEY[i] < min)
                {
                    min = KEY[i];
                    node = i;
                }
            }

            MST[node] = true;
            for (auto x : adj[node])
            {
                int ChildNode = x[0], weight = x[1];

                if (!MST[ChildNode] and weight < KEY[ChildNode])
                {
                    Parent[ChildNode] = node;
                    KEY[ChildNode] = weight;
                }
            }
        }
        int answer = 0;
        for (int i = 0; i < V; i++)
            answer += KEY[i];

        return answer;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        UsingMinHeap obj;
        NaiveApproach obj2;
        cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}
