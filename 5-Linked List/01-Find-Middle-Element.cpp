/*
Question Link:
LeetCode:https://leetcode.com/problems/middle-of-the-linked-list/
GFG:https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1
*/

#include <bits/stdc++.h>
using namespace std;

class naiveSolution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *temp = head;
        int length = 0;
        while (temp)
        {
            temp = temp->next;
            length++;
        }

        length = length / 2;
        temp = head;
        while (length--)
            temp = temp->next;

        return temp;
    }
};

// The intution behind this solution is that we have to find the answer in one iteration and that can be done by moving
// the fast pointer at twice the speed at which the slow pointer is moving

class BestSolution // O(n/2) && S(1)
{
public:
    ListNode *middleNode(ListNode *head)
    {

        ListNode *fast = head, *slow = head;

        while (fast && fast->next)
        {
            fast = fast->next->next;

            slow = slow->next;
        }

        return slow;
    }
};
