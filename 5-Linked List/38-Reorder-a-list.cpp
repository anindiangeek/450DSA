/*
Question Link:
LeetCode: https://leetcode.com/problems/reorder-list/
GFG: https://practice.geeksforgeeks.org/problems/reorder-list/1/
*/

#include <bits/stdc++.h>
using namespace std;
class using stack //O(n) & S(1)
{

}
class optimalSolution //O(n) & S(1)
{
    Node *reverse(Node *head)
    {
        if (!head || !head->next)
            return head;

        Node *rest = reverse(head->next);

        head->next->next = head;
        head->next = nullptr;
        return rest;
    }
    void reorderList(Node *head)
    {
        Node *fast = head, *slow = head;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        Node *list = slow->next;
        slow->next = nullptr;

        list = reverse(list);

        Node *node = head;
        while (list)
        {
            Node *temp = node->next;

            node->next = list;
            list = list->next;
            node = node->next->next = temp;
        }
    }
}
