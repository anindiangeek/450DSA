/*
Question Links:
https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1/#
https://leetcode.com/problems/maximum-depth-of-binary-tree/
*/

// O(n)
class DFS
{
public:
    // Function to find the height of a binary tree.
    int height(struct Node *node)
    {
        if (!node)
            return 0; // Reaching the last element of the tree

        return 1 + max(height(node->left), height(node->right));
    }
};

// O(n) & S(n)

// Intution: During the level order traversal, we will insert a null value in the queue and whenver we
// will encounter that null value we will increase the depth/height
class BFS
{
public:
    int height(struct Node *root)
    {
        int depth = 0;

        queue<Node *> q;

        // Pushing first level element along with NULL
        q.push(root);
        q.push(NULL);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();

            if (temp == NULL)
                depth++;

            // If NULL not encountered, keep moving
            if (temp != NULL)
            {
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }

            // If queue still have elements left,
            // push NULL again to the queue.
            else if (!q.empty())
            {
                q.push(NULL);
            }
        }
        return depth;
    }
}
}