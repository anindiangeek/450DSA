/*
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1#
*/

/**
 * Using an unordered set to store the unique values of the list and if finding the same value again
 * then removing it
 * Using unordered_set as it take O(1) in searching while set take O(log n)
 */
class Solution // O(n) & S(n)
{
public:
    Node *removeDuplicates(Node *head)
    {
        unordered_set<int> Hash;
        Node *current = head;
        Hash.insert(head->data);
        while (current && current->next)
        {
            if (!(Hash.find(current->next->data) == Hash.end()))
                current->next = current->next->next;
            else
            {
                current = current->next;
                Hash.insert(current->data);
            }
        }

        return head;
    }
}