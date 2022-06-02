/*
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1#
*/

/**
 */
class Solution
{
    void splitList(Node *head, Node **head1_ref, Node **head2_ref)
    {
        Node *slow = head, *fast = head;

        if (!head)
            return;

        // Getting the middle point

        while (fast->next != head && fast->next->next != head)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        // getting the last point of the list
        // If the list is even moving the fast pointer one step ahead then it will be at the node before head
        if (fast->next->next == head)
            fast = fast->next;

        // Setting the head of the first list
        *head1_ref = head;

        // Checking if the list is only one element or not and then setting the head of second list
        if (head->next != head)
            *head2_ref = slow->next;

        // making the second list circular
        fast->next = slow->next;

        // making the first list circular
        slow->next = head;
    }
}