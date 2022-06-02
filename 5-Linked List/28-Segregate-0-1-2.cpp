/*
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1#
*/

/**
 * Traverse the list and count the number of 0s, 1s, and 2s. Let the counts be n1, n2, and n3 respectively.
 * Traverse the list again, fill the first n1 nodes with 0, then n2 nodes with 1, and finally n3 nodes with 2.
 */
class Solution
{
public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node *segregate(Node *head)
    {

        // Counting the number of 0,1 and 2s

        int count[3] = {0, 0, 0};

        Node *temp = head;
        while (temp)
        {
            count[temp->data]++;
            temp = temp->next;
        }

        temp = head;

        while (temp)
        {
            if (count[0]-- > 0)
                temp->data = 0;
            else if (count[1]-- > 0)
                temp->data = 1;
            else if (count[2]-- > 0)
                temp->data = 2;

            temp = temp->next;
        }

        return head;
    }
}