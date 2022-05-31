/*
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1
*/

/**
 * Following Floyd's cycle detection algorithm
 *
 */
class Solution
{
    bool detectLoop(Node *head)
    {
        Node *fast = head, *slow = head;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow)
                return true;
        }

        return false;
    }
}