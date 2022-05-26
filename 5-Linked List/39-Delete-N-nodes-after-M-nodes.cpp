/*
Question Link:
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1#
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void linkdelete(struct Node *head, int M, int N)
    {
        Node*temp=head,*connect=head;

        while(connect)
        {11``
                temp=connect;
                connect=connect->next;
            }
            int y=N;
            while(y--&&connect)
            {
                connect=connect->next;
            }
            temp->next=connect;
        }
    }
}
