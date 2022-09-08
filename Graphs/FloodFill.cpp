#include <bits/stdc++.h>
using namespace std;

class DFS
{
public:
    int x[4] = {0, 0, 1, -1};
    int y[4] = {1, -1, 0, 0};
    void dfs(vector<vector<int>> &image, int sr, int sc, int color, int oldcolor)
    {
        image[sr][sc] = color;
        for (int i = 0; i < 4; i++)
        {
            int NewX = x[i] + sr, NewY = y[i] + sc;
            if (NewX >= 0 and NewY >= 0 and NewX < image.size() and NewY < image[0].size())
                if (image[NewX][NewY] == oldcolor)
                    dfs(image, NewX, NewY, color, oldcolor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        if (color == image[sr][sc])
            return image;
        int M = image.size(), N = image[0].size();
        int oldcolor = image[sr][sc];
        image[sr][sc] = color;
        dfs(image, sr, sc, color, oldcolor);
        return image;
    }
};

class BFS
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        if (color == image[sr][sc])
            return image;

        int x[] = {0, 0, 1, -1};
        int y[] = {1, -1, 0, 0};

        int rowsize = image.size(), colsize = image[0].size();
        int color2 = image[sr][sc];

        queue<pair<int, int>> q;

        q.push({sr, sc});
        image[sr][sc] = color;

        while (!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();

            for (int j = 0; j < 4; j++)
            {
                int m = p.first + x[j], n = p.second + y[j];

                if (m >= 0 and n >= 0 and m < rowsize and n < colsize)
                {
                    if (image[m][n] == color2)
                    {
                        q.push({m, n});
                        image[m][n] = color;
                    }
                }
            }
        }
        return image;
    }
};