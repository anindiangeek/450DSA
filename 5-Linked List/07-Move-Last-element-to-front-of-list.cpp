/*
LeetCode:
GFG: https://www.geeksforgeeks.org/move-last-element-to-front-of-a-given-linked-list/
*/

/**
 */
class Solution
{
    Node *move *(Node *head)
    {
        Node *temp = head, *beforetemp;
        while (temp->next)
        {
            beforetemp = temp;
            temp = temp->next;
        }
        beforetemp->next = nullptr;
        temp->next = head;
        head = temp;
        return head;
    }
}