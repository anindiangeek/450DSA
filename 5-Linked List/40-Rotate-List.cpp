/*
Question Link:
LeetCode: https://leetcode.com/problems/rotate-list/
GFG: https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1/
*/

#include <bits/stdc++.h>
using namespace std;

/*
1) Right Rotation of the list is nothing but connecting the nth node from behind as the new head
2) Finding out the length to get the position from behind as k can be > length
3) Getting to (n+1)th position from behind then disconnecting the list and making the nth position
   as a new head and making the fast'next point on previous head, which was the last node
*/

class rightSolution
{
    int length(ListNode *head)
    {
        ListNode *temp = head;
        int length = 0;
        while (temp)
        {
            length++;
            temp = temp->next;
        }

        return length;
    }

    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || k == 0)
            return head;

        k = k % length(head); // Finding out the exact number of times we have to rotate the list,
                              // because if list is rotated equal to it's length we get the original list

        if (!k)
            return head; // This means that we don't have to rotate the list

        ListNode *slow = head, *fast = head;

        while (k-- && fast)
            fast = fast->next;

        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode *newLastNode = slow->next;
        slow->next = nullptr;

        fast->next = head;
        head = newLastNode;

        return head;
    }
}

/*
1) Same concept as above, instead of counting from back we had to count from the front and then connect
*/

class leftSolution
{
    int length(Node *head)
    {
        Node *temp = head;
        int length = 0;

        while (temp)
        {
            temp = temp->head;
            length++;
        }

        return length;
    }

    Node *leftRotate(Node *head, int k)
    {
        Node *fast = head, *slow = head;

        while (fast->next)
            fast = fast->next;

        k--; //as we only want to travel k places from starting.
        while (k--)
        {
            slow = slow->next;
        }
        fast->next = head;

        Node *newhead = slow->next;
        slow->next = nullptr;

        head = newhead;

        return head;
    }
}
