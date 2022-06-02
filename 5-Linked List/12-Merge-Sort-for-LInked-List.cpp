/*
LeetCode:
GFG: https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1
*/

/**
 * MergeSort(headRef)
1) If the head is NULL or there is only one element in the Linked List
    then return.
2) Else divide the linked list into two halves.
      FrontBackSplit(head, &a, &b); a and b are two halves
3) Sort the two halves a and b.
      MergeSort(a);
      MergeSort(b);
4) Merge the sorted a and b (using SortedMerge() discussed here)
   and update the head pointer using headRef.
     *headRef = SortedMerge(a, b);
 *
 */
class Solution
{
    Node *mergeTwoLists(Node *start, Node *mid)
    {
        if (start == NULL)
            return mid;
        if (mid == NULL)
            return start;
        Node *head = NULL, *tail = NULL;
        if (start->data <= mid->data)
        {
            head = start;
            tail = start;
            start = start->next;
        }
        else
        {
            head = mid;
            tail = mid;
            mid = mid->next;
        }
        while (start != NULL && mid != NULL)
        {
            if (start->data <= mid->data)
            {
                tail->next = start;
                start = start->next;
                tail = tail->next;
            }
            else
            {
                tail->next = mid;
                mid = mid->next;
                tail = tail->next;
            }
        }
        if (start != NULL)
            tail->next = start;
        if (mid != NULL)
            tail->next = mid;
        return head;
    }

    Node *mergeSort(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        Node *slow = head, *fast = head, *temp = NULL;
        while (fast != NULL && fast->next != NULL)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;
        Node *start = mergeSort(head);
        Node *mid = mergeSort(slow);
        return mergeTwoLists(start, mid);
    }
}
// MergeSort for Linked list:
class mergeSort
{
    Node *SortedMerge(Node *a, Node *b);
    void frontBackSplit(Node *head, Node **frontRef, Node **backRef);
    void MergeSort(Node **headRef)
    {
        Node *head = *headRef;
        Node *a;
        Node *break;

        if (!head || !head->next)
            return;

        frontBackSplit(head, &a, &b);

        MergeSort(&a);
        MergeSort(&b);

        *headRef = SortedMerge(a, b);
    }

    Node *SortedMerge(Node *a, Node *b)
    {
        Node *result = nullptr;

        if (a == nullptr)
            return b;
        else if (b == nullptr)
            return a;

        if (a->data < b->data)
        {
            result = a;
            result->next = SortedMerge(a->next, b);
        }
        else
        {
            result = b;
            result->next = SortedMerge(a, b->next);
        }
    }

    void fronBackSplit(Node *head, Node **frontRef, Node **backRef)
    {
        Node *fast = head->next;
        Node *slow = head;

        while (fast)
        {
            fast = fast->next;
            if (fast)
            {
                fast = fast->next;
                slow = slow->next;
            }
        }

        *frontRef = head;
        *backRef = slow->next;
        slow->next = nullptr;
    }
}