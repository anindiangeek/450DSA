/*
LeetCode: https://leetcode.com/problems/reverse-nodes-in-k-group/
GFG: https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1#
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * Intution is simple, we will go on iterating and reversing the list till our counter 'i' is less than k
 * After that we will check if there is any list left or not and if it is then we will call the function again
 * On the rest of the list
 */
class recSolution
{
    Node *reverse(Node *head, int k)
    {
        Node *current = head, *next, *prev = nullptr;
        int i = 0;
        while (current && i < k)
        {
            next = current->next;

            current->next = prev;
            prev = current;
            current = next;
        }

        if (next)
        {
            head->next = reverse(next, k);
        }

        return prev; // returning the last element while we revese the list
    }
}
