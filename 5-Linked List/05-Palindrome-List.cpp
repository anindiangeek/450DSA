/*
Question Link:
LeetCode:https://leetcode.com/problems/palindrome-linked-list/
GFG:https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1/#
*/

#include <bits/stdc++.h>
using namespace std;

/*
1) Inserting all the elements in a stack
2) Traversing the list again and checking from the stack top
*/

class usingStack // O(N) & S(N)
{
    bool palindrome(Node *head)
    {
        stack<int> s;

        Node *t = head;

        while (t)
        {
            s.push(t->data);
            t = t->next;
        }

        t = head;
        int check;
        while (t)
        {
            check = s.top();
            s.pop();
            if (t->data != check)
                return 0;
            t = t->next;
        }

        return 1;
    }
}

/*
1) Get the middle of the linked list.
2) Reverse the second half of the linked list.
3) Check if the first half and second half are identical.
4) Construct the original linked list by reversing the second half again and attaching it
   back to the first half
*/

class bestSolution // O(N) & S(1)
{
    Node *reverse(Node *head)
    {
        Node *pre = NULL;
        Node *next = NULL;
        while (head != NULL)
        {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
    bool isPalindrome(Node *head)
    {
        Node *fast = head, *slow = head;

        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        fast = head;

        slow->next = reverse(slow->next);

        Node *reversed = slow;

        slow = slow->next;

        bool palidrome = 1;

        while (slow != nullptr)
        {
            if (fast->data != slow->data)
                palindrome = 0;
            fast = fast->next;
            slow = slow->next;
        }

        reversed->next = reverse(reversed->next); // Getting back the original List

        return palindrome;
    }
}

/*
The idea is to use function call stack as a container. Recursively traverse till the end of list.
When we return from last NULL, we will be at the last node. The last node to be compared with
first node of list.

In order to access first node of list, we need list head to be available in the last call of
recursion. Hence, we pass head also to the recursive function. If they both match we need to
compare (2, n-2) nodes. Again when recursion falls back to (n-2)nd node, we need reference to 2nd
node from the head. We advance the head pointer in the previous call, to refer to the next node
in the list.

However, the trick is identifying a double-pointer. Passing a single pointer is as good as
pass-by-value, and we will pass the same pointer again and again. We need to pass the address of
the head pointer for reflecting the changes in parent recursive calls.

O(N) & S(N) if Function Call Stack size is considered, otherwise S(1).
*/

class recursiveSolution
{
    bool palindrome(Node **left, Node *right)
    {
        if (!right)
            return true;

        if (!palindrome(left, right->next))
            return false;

        bool answer = (right->data == (*left)->data);

        *left = (*left)->next;

        return answer;
    }
    bool isPalindrome(Node *head)
    {
        return palindrome(&head, head);
    }
}
