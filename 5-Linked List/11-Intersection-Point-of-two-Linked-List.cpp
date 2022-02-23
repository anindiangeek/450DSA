/*
    Problem Link:
    * https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1
    * https://leetcode.com/problems/intersection-of-two-linked-lists/

    Solution :
    - 1) A naive solution could be to store all the address and check if we revisit that address again while traversing
   from the other head;
    - 2) A space effecient algorithm is implimented below.
    - 3) there exists a method to do this without getting the lenght of the lists.

    Best Solution :
    https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/49785/Java-solution-without-knowing-the-difference-in-len!

    All Solutions :
    https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1
*/

#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
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

/*
    We can do this without using the difference between the lengths of lists.

    Visualization of this solution:
Case 1 (Have Intersection & Same Len):

       a
A:     a1 → a2 → a3
                   ↘
                     c1 → c2 → c3 → null
                   ↗
B:     b1 → b2 → b3
       b
            a
A:     a1 → a2 → a3
                   ↘
                     c1 → c2 → c3 → null
                   ↗
B:     b1 → b2 → b3
            b
                 a
A:     a1 → a2 → a3
                   ↘
                     c1 → c2 → c3 → null
                   ↗
B:     b1 → b2 → b3
                 b
A:     a1 → a2 → a3
                   ↘ a
                     c1 → c2 → c3 → null
                   ↗ b
B:     b1 → b2 → b3
Since a == b is true, end loop while(a != b), return the intersection node a = c1.

Case 2 (Have Intersection & Different Len):

            a
A:          a1 → a2
                   ↘
                     c1 → c2 → c3 → null
                   ↗
B:     b1 → b2 → b3
       b
                 a
A:          a1 → a2
                   ↘
                     c1 → c2 → c3 → null
                   ↗
B:     b1 → b2 → b3
            b
A:          a1 → a2
                   ↘ a
                     c1 → c2 → c3 → null
                   ↗
B:     b1 → b2 → b3
                 b
A:          a1 → a2
                   ↘      a
                     c1 → c2 → c3 → null
                   ↗ b
B:     b1 → b2 → b3
A:          a1 → a2
                   ↘           a
                     c1 → c2 → c3 → null
                   ↗      b
B:     b1 → b2 → b3
A:          a1 → a2
                   ↘                a = null, then a = b1
                     c1 → c2 → c3 → null
                   ↗           b
B:     b1 → b2 → b3
A:          a1 → a2
                   ↘
                     c1 → c2 → c3 → null
                   ↗                b = null, then b = a1
B:     b1 → b2 → b3
       a
            b
A:          a1 → a2
                   ↘
                     c1 → c2 → c3 → null
                   ↗
B:     b1 → b2 → b3
            a
                 b
A:          a1 → a2
                   ↘
                     c1 → c2 → c3 → null
                   ↗
B:     b1 → b2 → b3
                 a
A:          a1 → a2
                   ↘ b
                     c1 → c2 → c3 → null
                   ↗ a
B:     b1 → b2 → b3
Since a == b is true, end loop while(a != b), return the intersection node a = c1.

Case 3 (Have No Intersection & Same Len):

       a
A:     a1 → a2 → a3 → null
B:     b1 → b2 → b3 → null
       b
            a
A:     a1 → a2 → a3 → null
B:     b1 → b2 → b3 → null
            b
                 a
A:     a1 → a2 → a3 → null
B:     b1 → b2 → b3 → null
                 b
                      a = null
A:     a1 → a2 → a3 → null
B:     b1 → b2 → b3 → null
                      b = null
Since a == b is true (both refer to null), end loop while(a != b), return a = null.

Case 4 (Have No Intersection & Different Len):

       a
A:     a1 → a2 → a3 → a4 → null
B:     b1 → b2 → b3 → null
       b
            a
A:     a1 → a2 → a3 → a4 → null
B:     b1 → b2 → b3 → null
            b
                 a
A:     a1 → a2 → a3 → a4 → null
B:     b1 → b2 → b3 → null
                 b
                      a
A:     a1 → a2 → a3 → a4 → null
B:     b1 → b2 → b3 → null
                      b = null, then b = a1
       b                   a = null, then a = b1
A:     a1 → a2 → a3 → a4 → null
B:     b1 → b2 → b3 → null
            b
A:     a1 → a2 → a3 → a4 → null
B:     b1 → b2 → b3 → null
       a
                 b
A:     a1 → a2 → a3 → a4 → null
B:     b1 → b2 → b3 → null
            a
                      b
A:     a1 → a2 → a3 → a4 → null
B:     b1 → b2 → b3 → null
                 a
                           b = null
A:     a1 → a2 → a3 → a4 → null
B:     b1 → b2 → b3 → null
                      a = null
Since a == b is true (both refer to null), end loop while(a != b), return a = null.

Notice that if list A and list B have the same length, this solution will terminate in no more than 1 traversal; if both
lists have different lengths, this solution will terminate in no more than 2 traversals -- in the second traversal,
swapping a and b synchronizes a and b before the end of the second traversal. By synchronizing a and b I mean both have
the same remaining steps in the second traversal so that it's guaranteed for them to reach the first intersection node,
or reach null at the same time (technically speaking, in the same iteration) -- see Case 2 (Have Intersection &
Different Len) and Case 4 (Have No Intersection & Different Len).

*/
// the above method is Implimented below.
int IntersectPointBetterMethod(struct Node *head1, struct Node *head2) // O(N+M) S(1)
{
    if (head1 == nullptr or head2 == nullptr)
        return -1;

    Node *a = head1;
    Node *b = head2;

    while (a != b)
    {
        a = (a == nullptr) ? head2 : a->next;
        b = (b == nullptr) ? head1 : b->next;
    }

    return a->data;
}

int intersectPoint(struct Node *head1, struct Node *head2) // O(M+N) S(1)
{
    int length1 = 0, length2 = 0;

    bool HasIntersection = false;

    Node *itr1 = head1, *itr2 = head2, *IntersectionNode = nullptr;

    for (; itr1; itr1 = itr1->next, length1++)
        ;

    for (; itr2; itr2 = itr2->next, length2++)
        ;

    int skip = max(length1, length2) - min(length1, length2);

    itr1 = head1;
    itr2 = head2;

    if (length1 > length2)
        for (int i = 1; i <= skip; itr1 = itr1->next, i++)
            ;
    else if (length1 < length2)
        for (int i = 1; i <= skip; itr2 = itr2->next, i++)
            ;
    else
    {
        assert(skip == 0);
    }

    while (itr1 && itr2)
    {
        if (itr1->next == itr2->next && itr1->next != nullptr)
        {
            HasIntersection = true;
            IntersectionNode = itr1->next;
            return IntersectionNode->data;
        }
        itr1 = itr1->next;
        itr2 = itr2->next;
    }
    return -1;
}

Node *inputList(int size)
{
    if (size == 0)
        return NULL;

    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

/* Driver program to test above function*/
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("C://450DSA//i.txt", "r", stdin);
    freopen("C://450DSA//e.txt", "w+", stderr);
#endif
    int T, n1, n2, n3;

    cin >> T;
    while (T--)
    {
        cin >> n1 >> n2 >> n3;

        Node *head1 = inputList(n1);
        Node *head2 = inputList(n2);
        Node *common = inputList(n3);

        Node *temp = head1;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;

        temp = head2;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;

        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}
