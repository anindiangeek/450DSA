/*
Question Link: https://practice.geeksforgeeks.org/problems/sum-tree/1

Basic Intuition:
Get the sum of nodes in the left subtree and right subtree.
Check if the sum calculated is equal to the root’s data.
Also, recursively check if the left and right subtrees are SumTrees.
*/

class naiveSolution // O(n^2) & S(1)
{

    int sum(Node *root)
    {
        if (!root)
            return 0;

        return sum(root->left) + root->data + sum(root->right);
    }
    bool isSum(Node *root)
    {
        int ls, rs;

        if (!root)
            return 1;

        if (!root->left && !root->right)
            return 1;

        ls = sum(root->left);
        rs = sum(root->right);

        if (root->data == ls + rs && isSum(root->left) && isSum(root->right))
            return 1;

        return 0;
    }
};

/*
Approach:
In the above aproach we were calculating sum for each and every node,
Which was increasing the overall time complexity for the solution.
We can do better than that.

* If the node's children are leaf nodes then the sum will be equal to child's values
* If they are non leaf then the sum for the subtrees will be double their value

*/

class optimisedSol //O(n) & S(1)
{

    bool isLeaf(Node *root)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;
        return 0;
    }

    bool isSum(Node *root)
    {
        int ls, rs;

        if (!root || isLeaf(root))
            return 1;

        if (isSum(root->left) && isSum(root->right))
        {

            if (root->left == nullptr)
                ls = 0;
            else if (isLeaf(root->left))
                ls = root->left->data;
            else
                ls = 2 * root->left->data;

            if (root->right == nullptr)
                rs = 0;
            else if (isLeaf(root->right))
                rs = root->right->data;
            else
                rs = 2 * root->right->data;

            if (ls + rs == root->data)
                return 1;
            return 0;
        }

        return 0;
    }
}