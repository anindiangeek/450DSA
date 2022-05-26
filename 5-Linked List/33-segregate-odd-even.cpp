/*
Question Link:
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1#
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    Node *divide(int N, Node *head)
    {
        Node *evenstart = nullptr, *oddstart = nullptr;

        Node *even, odd;

        Node *temp = head;

        while (temp)
        {
            if ((temp->data) % 2 == 0)
            {
                if (!evenstart)
                {
                    evenstart = temp;
                    even = temp;
                }
                else
                {
                    even->next = temp;
                    even = even->next;
                }
            }
            else
            {
                if (!oddstart)
                {
                    oddstart = temp;
                    odd = temp;
                }
                else
                {
                    odd->next = temp;
                    odd = odd->next;
                }
            }

            temp = temp->next;
        }

        if (evenstart == NULL)
            return oddstart;
        if (odd != NULL)
            odd->next = NULL;

        even->next = oddstart;
        return evenstart;
    }
}
