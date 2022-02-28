/* @anindiangeek */
#include <bits/stdc++.h>
using namespace std;
/*

  * Given a root binary tree, check if it is a BST.
	Properties of BST
	* The left subtree of a node contains only nodes with keys less than the
  node’s key.
	* The right subtree of a node contains only nodes with keys greater than the
  node’s key.
	* Both the left and right subtrees must also be binary search trees.

  Problem Link : https://leetcode.com/problems/balanced-binary-tree/

  Possible explanation:
  https://leetcode.com/problems/balanced-binary-tree/discuss/35691/The-bottom-up-O(N)-solution-would-be-better
  https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/

*/

class ConstantSpaceIterativeapproach // O(N) && S(1) // HARD
{
	/*  We will use morris Inorder traversal for traversing in constanst space and we will check if the previous
		Node has illeagl value as the values must come in sorted order in case of INorder traversal of Binary tree.
		https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/
	*/

public:
	// left to implement later. @yashaswashukla
	bool isValidBST(TreeNode *root)
	{
	}
};
class RecursiveInorderApproach // O(N) && S(Height of Tree)
{
	/*
	  we will use a important property of BST, an In-order traversal of BST serialise the nodes, i.e it will yield a sorted array.
	  here we will use recusrion to achieve this.
	*/
public:
	TreeNode *PreviousNode = nullptr;
	bool isValidBST(TreeNode *root)
	{
		if (!root)
			return true;

		if (!isValidBST(root->left))
			return false;

		if (PreviousNode /* Exists */ && PreviousNode->val >= root->val)
			return false;

		PreviousNode = root;

		if (!isValidBST(root->right))
			return false;

		return true;
	}
};
class IterativeInorderApproach // O(N) & S(N)
{
	/*
	  we will use a important property of BST, an In-order traversal of BST serialise the nodes, i.e it will yield a sorted array.
	*/
public:
	bool isValidBST(TreeNode *root)
	{
		stack<TreeNode *> s;
		TreeNode *PreviousNode = nullptr;
		while (root or !s.empty())
		{
			while (root)
			{
				s.push(root);
				root = root->left;
			}
			root = s.top();
			s.pop();
			if (PreviousNode && root->val <= PreviousNode->val)
				return false;
			PreviousNode = root;
			root = root->right;
		}
		return true;
	}
};
class NaiveTopDown // O(N^2) and S(height of tree) {recursive stack space}
{
	/*
	  A lot of things can go wrong in this apporach, and it is slower as we are iterating nodes over and over again to get minimum and maximum.
	  also if there are mutiple values of INT_MAX and INT_MIN things can go wrong as well.
	*/
public:
	// https://www.geeksforgeeks.org/find-maximum-or-minimum-in-binary-tree/
	int MaximumLeft(TreeNode *root)
	{
		if (!root)
			return INT_MIN;
		int temp = max(MaximumLeft(root->left), MaximumLeft(root->right));
		return max(temp, root->val);
	}

	int MinimumRight(TreeNode *root)
	{
		if (!root)
			return INT_MAX;
		int temp = min(MinimumRight(root->left), MinimumRight(root->right));
		return min(temp, root->val);
	}

	bool isValidBST(TreeNode *root)
	{
		if (!root)
			return true;

		if (root->left && MaximumLeft(root->left) >= root->val)
			return false;

		if (root->right && MinimumRight(root->right) <= root->val)
			return false;

		if (!isValidBST(root->left) or !isValidBST(root->right))
			return false;

		return true;
	}
};

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right)
		: val(x), left(left), right(right) {}
};
int main()
{
}