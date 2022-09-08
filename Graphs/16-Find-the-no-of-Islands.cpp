/*
    Q: https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1

    Given a grid of size n*m consisting of '0's (Water) and '1's(Land).
    Find the number of islands.
    Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally
    i.e., in all 8 directions.

    Or

    this problem can be reduced to find connected components.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution2
{
public:
    int dir[8][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
    void dfs(int x, int y, vector<vector<char>> &grid)
    {
        grid[x][y] = '2';

        for (int i = 0; i < 8; i++)
        {
            int p = dir[i][0] + x, q = dir[i][1] + y;
            if (p < grid.size() and p >= 0 and q < grid[0].size() and q >= 0)
            {
                if (grid[p][q] == '1')
                    dfs(p, q, grid);
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int answer = 0, r = grid.size(), c = grid[0].size();

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(i, j, grid);
                    answer++;
                }
            }
        }

        return answer;
    }
};

class Solution
{
public:
    int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int numIslands(vector<vector<char>> &grid)
    {
        int answer = 0, r = grid.size(), c = grid[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (grid[i][j] == '1')
                {
                    q.push({i, j});
                    while (!q.empty())
                    {
                        auto it = q.front();
                        q.pop();
                        grid[it.first][it.second] = '2';
                        for (auto coordinates : dir)
                        {
                            int newx = coordinates[0] + it.first, newy = coordinates[1] + it.second;
                            if (newx < r and newx >= 0 and newy < c and newy >= 0)
                                if (grid[newx][newy] == '1')
                                    q.push({newx, newy});
                        }
                    }
                    answer++;
                }

        return answer;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}