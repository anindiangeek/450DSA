/*
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/multiply-two-linked-lists/1#
*/

/**
 */
class Solution
{
    long long multiplyTwoLists(Node *l1, Node *l2)
    {
        long long a = 1000000007;

        long long s1 = 0;
        long long s2 = 0;

        while (l1)
        {

            s1 = (s1 * 10) % a + l1->data;
            l1 = l1->next;
        }

        while (l2)
        {

            s2 = (s2 * 10) % a + l2->data;
            l2 = l2->next;
        }

        return ((s1 * s2) % a);
    }
}