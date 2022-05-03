/*
Question Link:
LeetCode: https://leetcode.com/problems/copy-list-with-random-pointer/
GFG: https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1#
*/

#include <bits/stdc++.h>
using namespace std;

/*

1) Storing the address for the nodes and their deep copies in a hash map.
2) Updating the next and random pointers of the deep copies using hash map. As, we have the copies of
   all the nodes next to them in a map.

*/

class hashMapSolution
{
    Node *copyRandomList(Node *head)
    {
        Node *originalHead = head;
        map<Node *, Node *> map;

        while (originalHead)
        {
            map[originalHead] = new Node(originalHead->val);
            originalHead = originalHead->next;
        }

        originalHead = head;

        while (originalHead)
        {
            map[originalHead]->next = map[originalHead->next];
            map[originalHead]->random = map[originalHead->random];
            originalHead = originalHead->next;
        }

        return map[head];
    }
}

/*
1) Iterate the original list and duplicate each node. Modify the original list and place all the
   duplicates next to the original nodes.
2) Iterate the modified list and assign the random pointer for each duplicated node.
3) Restore the original list and extract the duplicated nodes.

Best explanation: https://leetcode.com/problems/copy-list-with-random-pointer/discuss/1059181/C%2B%2B-or-Three-Pass-or-O(n)-0ms-Beats-100-or-Explanation-(with-example)
*/
class optimalSolution
{
    Node *copyRandomList(Node *head)
    {
        // First step, copying the nodes and placing them next to each other

        Node *node = head;

        while (node)
        {
            Node *temp = node->next;
            node->next = new Node(node->data);
            node->next->next = temp;
            node = temp;
        }

        // Second step, assign the random pointers to the duplicates
        node = head;
        Node *duplicate = node->next;
        while (duplicate->next)
        {
            if (node->arb)
                duplicate->arb = node->arb->next;
            node = duplicate->next;
            duplicate = node->next;
        }

        // Third step, extracting the copied list

        Node *duplist = new Node(0); // Just a dummy node
        Node *duplicate = duplist;
        node = head;
        while (node)
        {
            duplicate->next = node->next;
            duplicate = duplicate->next;

            node->next = node->next->next;
            node = node->next;
        }
        return duplist->next;
    }
}
