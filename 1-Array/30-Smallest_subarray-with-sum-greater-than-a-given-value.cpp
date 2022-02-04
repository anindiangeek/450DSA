/*
    * couldn't find the question but got a article with the solution explanation.
    Problem Statement: return a smallest sub-array whose sum is greater than a given value x.
    * Similar Problem Statements.
    * https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1
    * https://leetcode.com/problems/minimum-size-subarray-sum/


    * https://www.geeksforgeeks.org/minimum-length-subarray-sum-greater-given-value/

*/

#include <bits/stdc++.h>
using namespace std;

class Solution // O(N) S(1)
{
  public:
    int minSubArrayLen(int Target, vector<int> &nums)
    {
        unsigned int answer = INT_MAX, CurrentSum = 0, Tail = 0, Head = 0;
        for (; Tail < nums.size(); Tail++)
        {
            CurrentSum += nums[Tail];

            while (CurrentSum >= Target)
            {
                answer = min(answer, Tail - Head + 1);
                CurrentSum -= nums[Head++];
            }
        }
        return (answer == INT_MAX) ? 0 : answer;
    }
};
class BinarySearch
{
  public:
    int minSubArrayLen(int Target, vector<int> &nums)
    {
    }
};

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    int value = 11;

    Solution ob;

    // vector<int> a =
    cout << ob.minSubArrayLen(value, v) << endl;
}