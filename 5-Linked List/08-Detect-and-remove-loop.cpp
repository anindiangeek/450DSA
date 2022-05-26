/*
Question Link:
LeetCode: https://leetcode.com/problems/linked-list-cycle-ii/
GFG: https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1/
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * Intution: First detect a loop in the linked list and when fast==slow, Apply the algorithm to find the
 * starting point of that loop and keep a pointer trailing the slow pointer, i.e. a pointer just behind slow
 * which will be our pointer to the last node of the loop.
 */

class leetCodeSol
{
    void findStartingOfTheLoop(Node *head)
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

                removenext->next = nullptr; // Very important to do this here, because if the loop is not broken here, then the loop will go on forever as it is in a loop
            }
        }
    }
}
