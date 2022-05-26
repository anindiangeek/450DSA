/*
    * https://leetcode.com/problems/middle-of-the-linked-list/
    * https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1

    LeetCode Solution is enough and has good explanation.

    some compilers will not work in while(fast->next)
    as we cannot acess null's next. and will cause runtime error. (espically leetcode)
    though the same code works on other comiler and online judge.

*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

/* Link list Node
struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}; */
class BetterSolution // O(N) S(1)
{
    /*
     * Here we will use the concept of slow & fast pointers.
     * if an object moves twice as fast than the another object then slow one will be at half the distance travelled by
     * th fast one. thus if the fast is at the end the slow will definately at the middle. by this intution we will get
     * the algorithm which works in single scan.
     */
  public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        // solution from leetcode there question was different we had to return the pointer to the middle element.
        /*  if (!head)
             return nullptr;
         ListNode *fast = head, *slow = head;
         while (fast and fast->next)
         {
             slow = slow->next;
             fast = fast->next->next;
         }
         return slow; */
    }
};

class NaiveSolution // O(N) S(1)
{
    /*
        Will iterate over list twice first to get length and later to reach middle of the list.
        N + N/2 = O(N)
    */
  public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {

        if (!head)
            return -1;
        int length = 0;
        Node *itr = head;

        while (itr)
        {
            itr = itr->next;
            length++;
        }

        length = (length & 1) ? ((length + 1) / 2) - 1 : (length / 2);
        itr = head;
        while (length)
        {
            itr = itr->next;
            length--;
        }

        return itr->data;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int data;
        cin >> data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N - 1; ++i)
        {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
        }

        NaiveSolution ob;
        cout << ob.getMiddle(head) << endl;
    }
    return 0;
}