class _2stackSolution
{

    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {

        if (!root)
            return {};

        vector<vector<int>> ans;

        stack<TreeNode *> s1, s2; // Using stack to store and traverse in zigzag order

        s1.push(root);

        while (!s1.empty() || !s2.empty())
        {
            vector<int> level;
            // Taking s1 and storing elements in left-to-right order
            // Hence it will give their children in right-to-left order
            while (!s1.empty())
            {
                TreeNode *temp = s1.top();
                s1.pop();

                level.push_back(temp->val);

                if (temp->left)
                    s2.push(temp->left);
                if (temp->right)
                    s2.push(temp->right);
            }
            if (level.size())
                ans.push_back(level);

            // Clearing the vector to avoid storing the next level values which are stored in s2
            level.clear();

            while (!s2.empty())
            {
                TreeNode *temp = s2.top();
                s2.pop();

                level.push_back(temp->val);

                if (temp->right)
                    s1.push(temp->right);
                if (temp->left)
                    s1.push(temp->left);
            }
            if (level.size())
                ans.push_back(level);
        }

        return ans;
    }
};

//Using deque to store the elements
//For spiral order we use a flag which indicates the position we have to insert and take out

class dequeSolution
{
    vector<vector<int>> zigzag(Node *root)
    {
        vector<vector<int>> res;
        if (!root)
            return res;
        std::deque<TreeNode *> deq;
        deq.push_back(root);
        int rtl = 1;
        while (!deq.empty())
        {
            int sz = deq.size();
            rtl = rtl ^ 1;
            vector<int> row;
            while (sz--)
            {
                if (rtl)
                { // pop_front, push_back, right then left
                    root = deq.front();

                    deq.pop_front();
                    
                    row.push_back(root->val);
                    
                    if (root->right)
                        deq.push_back(root->right);
                    if (root->left)
                        deq.push_back(root->left);
                }
                else
                { 
                    // pop_back, push_front, left then right
                    
                    root = deq.back();
                    
                    deq.pop_back();
                    
                    row.push_back(root->val);
                    
                    if (root->left)
                        deq.push_front(root->left);
                    if (root->right)
                        deq.push_front(root->right);
                }
            }
            res.push_back(row);
        }
        return res;
    }
}