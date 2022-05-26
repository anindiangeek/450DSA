/*
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1#
*/

/**
 */
class Solution
{
    Node *ReverseList(Node *curr)
    {

        Node *prev, *aftr;
        prev = aftr = NULL;

        while (curr)
        {

            aftr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = aftr;
        }

        return prev;
    }

    Node *addOne(Node *head)
    {
        // Your Code here
        // return head of list after adding one
        head = ReverseList(head);
        Node *curr = head;
        bool moveforward = true;

        while (curr != NULL and moveforward != false)
        {
            if (curr->data == 9 && curr->next == NULL)
            {
                curr->data = 1;
                Node *temp = new Node(0);
                temp->next = head;
                head = temp;
                curr = curr->next;
            }
            else if (curr->data == 9)
            {
                curr->data = 0;
                curr = curr->next;
            }
            else if (curr->data != 9)
            {
                curr->data = (curr->data) + 1;
                curr = curr->next;
                moveforward = false;
            }
        }

        head = ReverseList(head);
        return head;
    }
}