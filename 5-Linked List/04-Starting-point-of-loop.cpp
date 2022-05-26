/*
LeetCode:
GFG:
*/

/**
 * 1. If a loop is found, initialize a slow pointer to head, let fast pointer be at its position.
 * 2. Move both slow and fast pointers one node at a time.
 * 3. The point at which they meet is the start of the loop.
 */
class Solution
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