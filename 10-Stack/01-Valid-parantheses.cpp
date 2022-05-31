/*
Question Link:
LeetCode: https://leetcode.com/problems/valid-parentheses/
GFG: https://practice.geeksforgeeks.org/problems/valid-expression1025/1/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool isValid(string s)
    {
        stack<char> t;
        int i;

        for (auto i : s)
        {

            if (i == '(' || i == '{' || i == '[')
            {
                t.push(i);
            }
            else
            {
                if (t.empty() || (t.top() == '(' && i != ')') || (t.top() == '{' && i != '}') || (t.top() == '[' && i != ']'))
                {
                    return false;
                }

                t.pop();
            }
        }

        return t.empty();
    }
}
