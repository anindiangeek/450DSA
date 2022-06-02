/*
LeetCode:
GFG:https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1#
*/

/**
 * Reversing the list and keeping the note of the largest member on the left side and making a new list and
 * keeping all the elements which have the value greater than the left side list
 */
class naiveSolution // O(n) & S(1)
{
    Node *reverse(Node *head)
    {
        Node *pre = NULL, *curr = head, *next;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        return pre;
    }
    Node *compute(Node *head)
    {
        head = reverse(head);
        int maxi = -10;
        Node *temp = head;
        Node *head1 = new Node(0);
        Node *temp1 = head1;
        while (temp != NULL)
        {
            if (temp->data >= maxi)
            {
                Node *ans = new Node(temp->data);
                temp1->next = ans;
                maxi = temp->data;
                temp1 = temp1->next;
            }
            temp = temp->next;
        }
        head1 = reverse(head1->next);
        return head1;
    }
};

/**
 * In this solution we are using the recursion and finding out the largest value in the right side of a node
 * and comparing that value with the node's value if the node's value is greater than that then we make that
 * node the next node of our original node.
 * Else we return the old node.
 *
 */

class recSolution // O(N)
{
    Node *compute(Node *head)
    {
        Node *compute(Node * head)
        {
            // Checking if the head is not null or the if the head is is last node,if it is the last node
            // we return that node
            if (!head || !head->next)
                return head;

            // Finding out the correct order list on the right side of the node

            Node *nodeNext = compute(head->next);

            // Checking if the node on the right is greater or smaller
            // If greater then we return that node
            if (nodeNext->data > head->data)
                return nodeNext;

            // If smaller then we make that node the next node of our original list

            head->next = nodeNext;
            // And return that list
            return head;
        }
    }
}