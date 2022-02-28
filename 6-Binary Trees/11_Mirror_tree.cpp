/*
Question Link: https://practice.geeksforgeeks.org/problems/mirror-tree/1

Approach: we will swap the left and right nodes and then recursively call the function for it's left and right child
*/

class recSol
{
    void mirror(Node*root)
    {
        if(!root)
        return;

        Node * temp= root->left;
        root->left=root->right;
        root->right=temp;

        mirror(root->left);
        mirro(root->right);

        return;
    }
}