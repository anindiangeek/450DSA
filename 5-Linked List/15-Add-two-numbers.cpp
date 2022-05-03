/*
Question Link:
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1
*/

#include <bits/stdc++.h>
using namespace std;

class gfgSolution
{
    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        int a = 0, b = 0;
        while (first)
        {
            a = a * 10 + first->data;
        }
        while (second)
        {
            b = b * 10 + second->data;
        }

        int c = a + b;

        Node *answer = nullptr;
        while (c)
        {
            int x = c % 10;
            if (answer == NULL)
            {
                answer->data = x;
            }

            Node *temp = new Node(x);
            temp->next = answer;
            answer = temp;
            c = c / 10;
        }
    }
}
