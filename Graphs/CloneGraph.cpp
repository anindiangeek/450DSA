#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        unordered_map<Node *, Node *> Hash;
        queue<Node *> q;

        Node *NG = new Node(node->val);
        Hash[node] = NG;
        q.push(node);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();

            for (auto x : temp->neighbors)
            {

                if (Hash.find(x) == Hash.end())
                {
                    Node *NewNode = new Node(x->val);
                    Hash[x] = NewNode;
                    q.push(x);
                }
                Hash[temp]->neighbors.push_back(Hash[x]);
            }
        }
        return NG;
    }
};