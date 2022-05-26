/*
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1
*/

/**
 * Keeping a pointer on the current node and checking the node next to it.
 * If a duplicate is found then we remove it
 *
 */
class iterativeSolution // O(n) & S(1)
{
    Node *removeDuplicates(Node *head)
    {
        Node *current = head;

        while (current->next)
        {
            Node *next = current->next;

            if (current->data == next->data)
            {
                current->next = current->next->next;
            }
            else
                current = current->next;
        }

        return head;
    }
};

/**
 * @brief
 *
 */

class recSolution
{
}
