/*
    * https://leetcode.com/problems/3sum/
    * https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1

    * Solutions:
    * https://www.geeksforgeeks.org/find-a-triplet-that-sum-to-a-given-value/
*/

#include <bits/stdc++.h>
using namespace std;

class GoodSolution // O(N^2) & S(1)
{
    // we can sort the array in O(NLogN) time and use Two pointer technique to solve two sum problem for every value of
    // N. us the upper bound is already O(N^2) sorting will not be the bottleneck
  public:
    bool TwoSum(int A[], int size, int TargetSum, int j)
    {
        // Two Pointers
        int start = j + 1; // j+1 as we have to start looking from next index
        int end = size - 1;

        while (start < end)
        {
            int CurrentSum = A[start] + A[end];

            if (CurrentSum == TargetSum)
                return true;
            else if (CurrentSum < TargetSum)
                ++start;
            else
                --end;
        }

        return false;
    }

    bool find3Numbers(int A[], int size, int X)
    {
        sort(A, A + size);

        // it's better to go size-3 to avoid out of bounds and doing unnecessary calculations.
        for (int i = 0; i <= size - 3; i++)
        {
            int TargetSum = X - A[i];
            // function call to Two sum for Y;
            if (TwoSum(A, size, TargetSum, i))
                return true;
        }
        return false;
    }
};

class BetterSolution // O(N^2) & S(1)
{
    // we will use technique used in Two-sum to optimise this.
    // for each value N, we will find a two sum for N-1 values of (X- Nth) value
  public:
    bool TwoSum(int A[], int size, int Y, int j)
    {
        unordered_set<int> Hash;
        for (int i = j; i < size; i++)
        {
            if (Hash.find(Y - A[i]) != Hash.end())
                return true;
            Hash.insert(A[i]);
        }
        return false;
    }

    bool find3Numbers(int A[], int size, int X)
    {
        for (int i = 0; i <= size - 3; i++)
        {
            int Y = X - A[i];
            // function call to Two sum for Y;
            if (TwoSum(A, size, Y, i + 1))
                return true;
        }
        return false;
    }
};

class Bruteforce // O(size^3) & S(1)
{
  public:
    bool find3Numbers(int A[], int size, int X)
    {
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                for (int k = 0; k < size; k++)
                    if (A[i] + A[j] + A[k] == X && i != j && j != k && k != i)
                        return true;
        return false;
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("C://450DSA//i.txt", "r", stdin);
    freopen("C://450DSA//e.txt", "w+", stderr);
#endif
    int T;
    cin >> T;
    while (T--)
    {
        int size, X;
        cin >> size >> X;
        int i, A[size];
        for (i = 0; i < size; i++)
            cin >> A[i];
        Bruteforce ON3;
        cout << ON3.find3Numbers(A, size, X) << endl;
    }
}