/*
LeetCode:
GFG: https://www.geeksforgeeks.org/find-pairs-given-sum-doubly-linked-list/
*/

/**
 */
class Solution
{
    void pairSum(Node *head, int sum)
    {
        Node *left = head;
        Node *right = head;
        // Getting to the last element in the linked list
        while (right->next)
            right = right->next;

        bool found = false;

        // If the pointers meet or cross eachother
        while (left != right && right->next != left)
        {
            if (left->data + right->data == sum)
            {
                found = true;
                cout << "First value: " << left->data << " Second Value: " << right->data << endl;
                left = left->next;
                right = right->prev;
            }
            else if (left->data + right->data < sum)
                left = left->next;
            else
                right = right->prev;
        }

        if (!found)
            cout << "Not Found\n";
    }
}