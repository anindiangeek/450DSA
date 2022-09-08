#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // returns true if the difference is of only one letter

    bool CheckDifference(string A, string B)
    {
        int count = 0;
        for (int i = 0; i < A.length(); i++)
            if (A[i] != B[i])
                count++;

        return count == 1;
    }

    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {

        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) // O(N)
            return 0;

        wordList.push_back(beginWord);

        unordered_map<string, vector<string>> adj;

        for (auto word : wordList) // O(N^2) visited[item] = 1;
                        Todo.push(item);
            for (int i = 0; i < wordList.size(); i++)
                if (CheckDifference(word, wordList[i]))
                    adj[word].push_back(wordList[i]);

        unordered_map<string, int> visited;
        queue<string> Todo;
        Todo.push(beginWord);
        visited[beginWord] = 1;

        int level = 1;

        while (!Todo.empty())
        {
            int QueueSize = Todo.size();

            while (QueueSize--)
            {
                auto word = Todo.front();

                if (word == endWord)
                    return level;

                Todo.pop();

                for (auto item : adj[word])
                {
                    if (visited.find(item) == visited.end())
                    {
                        visited[item] = 1;
                        Todo.push(item);
                    }
                }
            }
            level++;
        }

        // there is no path to reach the endword. like there is no intermediate words to reach there.
        return 0;
    }
};