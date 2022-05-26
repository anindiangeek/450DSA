/*
LeetCode: https://leetcode.com/problems/add-two-numbers/
GFG: https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1
*/

#include <bits/stdc++.h>
using namespace std;

class leetcodeSolution
{
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ptr = new ListNode(); // new list;
        ListNode *temp = ptr;

        int c = 0;

        while (l1 != NULL || l2 != NULL || c)
        {
            int sum = 0;

            if (l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            sum += c;
            c = sum / 10;
            ListNode *node = new ListNode(sum % 10);
            temp->next = node;
            temp = temp->next;
        }
        return ptr->next;
    }
};

/**
 * We are given two linked list, first we reverse both of them then we start to add them and we maintain a
 * variable carry which stores the extra values in it. When we finish adding all the elements of both the list
 * We check if there is anything in the carry or not, if there is we make a new node and add it to our exisiting
 * answer list, and reverse it.
 *
 */

class gfgSolution
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
    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        first = reverse(first);
        second = reverse(second);
        int c = 0;
        Node *ans = new Node(0);
        Node *ptr = ans;
        while (first || second)
        {
            int sum = 0;
            if (first)
            {
                sum += first->data;
                first = first->next;
            }

            if (second)
            {
                sum += second->data;
                second = second->next;
            }

            sum += c;
            c = sum / 10;
            Node *temp = new Node(sum % 10);
            ptr->next = temp;
            ptr = temp;
        }

        if (c)
        {
            Node *temp = new Node(c);
            ptr->next = temp;
            ptr = temp;
        }

        return reverse(ans->next);
    }
}
