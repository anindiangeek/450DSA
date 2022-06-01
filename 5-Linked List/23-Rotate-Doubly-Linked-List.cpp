/*
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/rotate-doubly-linked-list-by-p-nodes/1/#
*/

/**
 */
class Solution // O(N) & S(1)
{
public:
    Node *rotateDLL(Node *start, int p)
    {
        Node *current = start;
        int k = 0;
        // Finding the pth node in the list

        while (current && k < p - 1)
        {
            current = current->next;
            k++;
        }

        // p+1th node will be the new head of the list
        Node *newHead = current->next;

        newHead->prev = nullptr;
        current->next = nullptr;

        // Finding the last node of the list to connect the original start as it's next
        Node *last = newHead;

        while (last->next)
            last = last->next;

        // Setting the links from the last node to original start node
        last->next = start;
        start->prev = last;

        return newHead;
    }
};