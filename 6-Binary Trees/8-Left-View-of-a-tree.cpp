#include <bits/stdc++.h>
using namespace std;
/*
    Problem : Given a Binary tree print it's left (or right view).

    Right view of following tree is 1 3 7 8.

          1
       /     \
     2        3
   /   \      / \
  4     5   6    7
    \
     8

    Problem Links :
    https://www.geeksforgeeks.org/print-left-view-binary-tree/
    https://leetcode.com/problems/binary-tree-right-side-view/
*/

struct Node
{
    int data;
    Node *left;
    Node *right;
};

/*
    Left View using DFS.
    * we maintain a level and on each level, we push only one element
      we keep track wetther we have pushed a node(first node) on a particular level
      by using the size of the answer array.
*/
void dfs(Node *root, vector<int> &answer, int level)
{
    if (!root or !root->left)
        return;

    dfs(root->left, answer, level + 1);
    dfs(root->right, answer, level + 1);
}

vector<int> leftViewDFS(Node *root)
{

    if (!root)
        return {};

    vector<int> LeftView;
    dfs(root, LeftView, 1);

    return LeftView;
}

vector<int> leftView(Node *root)
{
    if (!root)
        return {};

    vector<int> LeftView;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int QueueSize = q.size();
        // no of child in a particular level
        // we need only the left(first) one
        LeftView.push_back(q.front()->data);
        while (QueueSize--)
        {
            Node *node = q.front();
            q.pop();

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }
    return LeftView;
}

Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        vector<int> vec = leftView(root);
        for (int x : vec)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
