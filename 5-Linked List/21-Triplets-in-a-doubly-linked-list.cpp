/*
LeetCode:
GFG: https://www.geeksforgeeks.org/count-triplets-sorted-doubly-linked-list-whose-sum-equal-given-value-x/
*/

/**
 * Using the same algorithm as in the previous question, just wrapping that in a loop so that we can get 3
 * values instead of two
 */
class Solution // O(N^2) S(1)
{
    int countPair(Node *first, Node *second, int x)
    {
        int countpair = 0;
        while (first && second && first != second && second->next != first)
        {
            if (first->data + second->data == x)
            {
                countpair++;
                first = first->next;
                second = second->prev;
            }
            else if (first->data + second->data < x)
                first = first->next;
            else
                second = second->prev;
        }

        return countpair;
    }

    int countTriplets(Node *head, int sum)
    {
        Node *current = head, *first, *last;

        int countTrip = 0;

        // Getting the last node of the list
        while (current->next)
            current = current->next;

        last = current;

        current = head;

        // Traversing the list and taking each element and searching for pairs whose sum is equal to sum-current->data;

        while (current)
        {
            // Taking the current->next as we cannot take the same element twice
            first = current->next;

            countTrip += countPair(first, last, sum - current->data);
        }

        return countTrip;
    }
}