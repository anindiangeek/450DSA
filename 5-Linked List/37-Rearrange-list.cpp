/*
Question Link
LeetCode: https://leetcode.com/problems/odd-even-linked-list/
GFG: https://practice.geeksforgeeks.org/problems/rearrange-a-linked-list/1/#
*/

#include <bits/stdc++.h>
using namespace std;

class gfgSolution
{
    void rearrangeEvenOdd(Node *head)
    {
        Node *oddlist = head;
        Node *evenlist = head->next;

        Node *odd = oddlist, *even = evenlist;

        while (odd->next && even->next)
        {
            odd->next = even->next;

            odd = odd->next;

            even->next = odd->next;

            even = even->next;
        }

        odd->next = evenlist;
        head = oddlist;
    }
}
