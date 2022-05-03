/*
Question Link:
LeetCode:https://leetcode.com/problems/remove-nth-node-from-end-of-list/
GFG:https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1/
*/

#include <bits/stdc++.h>
using namespace std;

class gfgSolution
{
public:
    int solution(ListNode *head, int n)
    {
        ListNode *fast = head, *slow = head;
        while (fast != NULL && n > 0)
        {
            fast = fast->next;
            n--;
        }

        if (n > 0)
            return -1;

        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }

        return slow->data;
    }
};

// Fast Pointer is moved forward first with n nodes then slow pointer is moved till fast becomes null
// this will guarantee that slow is n nodes behind the end & as we have to remove it we can just modify the link

class leetCodeSolution // O(n) & S(1)
{
public:
    ListNode *solution(ListNode *head, int n)
    {
        ListNode *fast = head, *slow = head;

        while (n-- && fast)
            fast = fast->next;

        if (!fast)
            return head->next;

        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        return head;
    }
}
