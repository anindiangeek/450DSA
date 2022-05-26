/*
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1#
*/

/**
 */

class Solution
{
    Node *findIntersection(Node *head1, Node *head2)
    {
        Node *first = head1;
        Node *second = head2;

        Node *answer = new Node(0); // New list for storing the answers
        Node *ptr = answer;

        while (first && second) // If one list exhausts then we cannot have any further common elements
        {
            if (first->data == second->data)
            {
                // Creating a new node and adding to the answer list
                Node *temp = new Node(first->data);
                ptr->next = temp;
                ptr = temp;

                // Iterating the first and the second list
                first = first->next;
                second = second->next;
            }
            // Now finding the smaller data list and incrementing it as the lists are in ascending order
            else if (first->data > second->data)
                second = second->next;
            else
                first = first->next;
        }

        return answer->next; // answer->next as first node is a dummy node
    }
}