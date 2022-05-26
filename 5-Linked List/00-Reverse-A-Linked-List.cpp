/*
Question Link:
LeetCode:https://leetcode.com/problems/reverse-linked-list/
GFG:
*/

#include <bits/stdc++.h>
using namespace std;

/*
   1) Divide the list in two parts - first node and
      rest of the linked list.
   2) Call reverse for the rest of the linked list.
   3) Link rest to first.
      fixing the next pointer of the element just next to head
   4) Fix head pointer
*/

class recursiveSolution // O(n) & S(1)
{
public:
    ListNode *reverse(ListNode *head)
    {

        if (!head || !head->next)
            return head;

        ListNode *rest = reverseList(head->next);

        head->next->next = head;
        head->next = nullptr;
        return rest;
    }
}

class iterativeSolution // O(N) & S(1)
{
public:
    ListNode *reverse(ListNode *head)
    {
        ListNode *current = nullptr, *nex = head, *previous = NULL;

        while (nex)
        {
            previous = current;
            current = nex;
            nex = nex->next;

            current->next = previous;
        }

        return current;
    }
}
