/*
Question Link:
LeetCode: https://leetcode.com/problems/linked-list-cycle-ii/
GFG: https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1/
*/

#include <bits/stdc++.h>
using namespace std;

/*

*/

class leetCodeSol
{
    void removeLoop(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return NULL;

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *entry = head;

        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                while (slow != entry)
                {
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return NULL;
    }
}

class gfgSolution
{
    void removeLoop(Node *head)
    {

        Node *slow = head;
        Node *fast = head;
        Node *removenext = head;

        while (fast->next && fast->next->next)
        {
            removenext = slow;
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                fast = head;
                while (slow != fast)
                {
                    removenext = slow;
                    slow = slow->next;
                    fast = fast->next;
                }

                removenext->next = nullptr;
            }
        }
    }
}
