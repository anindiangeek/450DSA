/*
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1#
*/

/**
 * We just have to swap the node's previous and the next nodes
 * Note: we have to swap the nodes not the values
 *
 */
class Solution
{
    Node *reverseDLL(Node *head)
    {
        // Checking for the cases where the list is empty or only have 1 element
        if (!head || !head->next)
            return head;

        Node *temp, *current = head;

        // Swapping the current's previous and next members
        // Swapping the nodes not the values
        while (current)
        {
            temp = current->prev;

            current->prev = current->next;

            current->next = temp;

            current = current->prev;
        }

        return temp->prev;
    }
}