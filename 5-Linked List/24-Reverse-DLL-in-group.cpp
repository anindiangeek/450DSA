/*
LeetCode:
GFG: https://www.geeksforgeeks.org/reverse-doubly-linked-list-groups-given-size/
*/

/**
 */
class Solution
{
    Node *reverse(Node *head, int k)
    {
        Node *current = head, *next, *prev = nullptr;
        int i = 0;

        while (current && i < k)
        {

            prev = current;
            next = current->next;

            current->next = current->prev;
            current->prev = next;

            current = current->prev;
        }

        if (next)
        {
            head->next = reverse(next, k);
            head->next->prev = head;
        }
        return prev;
    }
}