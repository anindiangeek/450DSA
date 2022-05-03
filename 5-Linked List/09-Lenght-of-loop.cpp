/*
Question Link:
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/find-length-of-loop/1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int countNodesinLoop(struct Node *head)
    {
        Node *fast = head, *slow = head;
        bool loop = false;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                loop = true;
                break;
            }
        }
        if (!loop)
            return 0;
        int count = 1;
        slow = slow->next;
        while (fast != slow)
        {
            slow = slow->next;
            count++;
        }
        return count;
    }
}
