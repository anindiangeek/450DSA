/*
    Problem Link(s): * https://leetcode.com/problems/spiral-matrix/
                     * https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1

    Explanation : https://www.youtube.com/watch?v=siKFOI8PNKM

    we will take 4 pointers
    Top
    Bottom
    Left
    Right

    This will be their initial position.
            L     R
            ⬇     ⬇
    T -->   X X X X
            X X X X
            X X X X
            X X X X
    B -->   X X X X

    we will move in given order and push elements into our answer list
    while(L<=R && T<=B):
        L->R
        T->B
        --> here we will add a special check to avoid repepetition of answers
        R->L
        B->T
    After each step we will Increase/descrease the origin pointer.
    * also watch out edge cases like, row only and column only matrix.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> answer; // for returning the answer

        int Left{0};                          // Left pointer init to 0
        int Right{(int)matrix[0].size() - 1}; // Right pointer init to size of row(M)
        int Top{0};                           // Top pointer init to 0
        int Bottom{(int)matrix.size() - 1};   // Bottom pointer init to size of column (N)

        while (Left <= Right and Top <= Bottom)
        {
            // Moving L -> R
            for (int i = Left; i <= Right; ++i)
                answer.push_back(matrix[Top][i]);
            ++Top; // removing the visited row

            // Moving T -> B
            for (int i = Top; i <= Bottom; ++i)
                answer.push_back(matrix[i][Right]);
            --Right; // removing the visited column

            // for row only and column only matrix and to handle edge cases.
            if (Top > Bottom or Left > Right)
                break;

            // Moving R -> L
            for (int i = Right; i >= Left; --i)
                answer.push_back(matrix[Bottom][i]);
            --Bottom; // removing the visited row

            // Moving B -> T
            for (int i = Bottom; i >= Top; --i)
                answer.push_back(matrix[i][Left]);
            ++Left; // removing the visited column
        }
        return answer;
    }
};

int main()
{
    vector<vector<int>> Matrix{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    vector<vector<int>> m{{1, 2}, {3, 4}};

    /*
        1 2 3   1   2   3
        4 5 6   8   9   4
        7 8 9   7   6   5
    */

    Solution ob;
    auto ok = ob.spiralOrder(m);

    for (auto c : ok)
        cerr << c << " ";
    cerr << endl;
}