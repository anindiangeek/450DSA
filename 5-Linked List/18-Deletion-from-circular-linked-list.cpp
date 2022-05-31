/*
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/deletion-and-reverse-in-linked-list/1/#
*/

/**
 */
class Solution
{
    void deleteNode(struct Node **head, int key)
    {
        Node *temp = *head;
        // Getting to the node before the key
        while (temp->next->data != key)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
    }

    /* Function to reverse the linked list */
    void reverse(struct Node **head)
    {
        // Deleting the circular link and convert to single linked list
        Node *last = *head;
        while (last->next != *head)
        {
            last = last->next;
        }
        last->next = nullptr;

        // Reversing the list
        last = *head;
        Node *curr = *head, *prev = nullptr, *next = nullptr;

        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Re-establishing the circular link
        last->next = prev;
        *head = prev;
    }
}