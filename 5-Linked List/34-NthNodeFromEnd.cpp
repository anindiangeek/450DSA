/*
 * Problem : https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 * Naive Method wiil be to get length first and then go to length - i + 1 th node to delete it.
 * we can solve it in one pass by using two-pointers + sliding windows.
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr)
    {
    }
    ListNode(int x) : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode *next) : val(x), next(next)
    {
    }
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // nth element from end will be length-i+1 th element form the begining.
        if (!head)
            return head;

        ListNode *ForwardNode = head, *BackNode = head;

        // moving forward pointer n nodes ahead and will maintain the the window size between Back and Forward Node.
        while (n--)
            ForwardNode = ForwardNode->next;

        if (!ForwardNode) // if the Forward node is already null then there is no node to delete.
            return head->next;

        // sliding the current window size till we reach the end.
        while (ForwardNode->next)
        {
            BackNode = BackNode->next;
            ForwardNode = ForwardNode->next;
        }

        // deleting the node. Not actually deleting but skipping it.
        BackNode->next = BackNode->next->next;

        return head;
    }
};