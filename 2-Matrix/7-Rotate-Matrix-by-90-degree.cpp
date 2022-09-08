#include <bits/stdc++.h>
using namespace std;
/*
    Q : https://practice.geeksforgeeks.org/problems/rotate-by-90-degree-1587115621/1
    S :https://www.geeksforgeeks.org/rotate-a-matrix-by-90-degree-in-clockwise-direction-without-using-any-extra-space/
*/

class Solution
{
public:
    void rotateby90(vector<vector<int>> &matrix, int N)
    {
        for (int i = 0; i < N; i++)
            for (int j = i; j < N; j++)
                swap(matrix[i][j], matrix[j][i]);

        for (int i = 0; i < N / 2; i++)
            swap(matrix[i], matrix[N - 1 - i]);
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n);

        for (int i = 0; i < n; i++)
        {
            matrix[i].assign(n, 0);
            for (int j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        ob.rotateby90(matrix, n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cout << matrix[i][j] << " ";
        cout << endl;
    }
    return 0;
}