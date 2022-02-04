/*
For a given array, we need to make an array palindrome. The only allowed operation on the array is merging the
elements. To merge two adjacent elements just simply replace them with their sum. The task is to find a minimum number
of merge operations to make a given array palindrome.

Input
The first line of input contains an integer N, representing the size of the array.
The second line of input contains N space-separated integers, representing the array elements.

Output
A minimum number of merge operations to make the given array as a palindrome.

Constraints
1 <= N <= 10000

Example #1
Input
3
20 999 20
Output
0
Explanation: The array is already in palindrome.
Example #2
Input
4
10 99 44 10
Output
1
Explanation: Merge 99 and 44, result array will be 10 143 10.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution // O(N) & S(1)
{
  public:
    int FindMinSteps(vector<int> &Array)
    {
        int steps = 0, FrontIndex = 0, LastIndex = Array.size() - 1;

        while (FrontIndex <= LastIndex)
        {
            // Already Palindrome move to a smaller sub problem.
            if (Array[FrontIndex] == Array[LastIndex])
            {
                ++FrontIndex;
                LastIndex--;
            }

            // Merge last elements.
            else if (Array[FrontIndex] > Array[LastIndex])
            {
                LastIndex--;
                Array[LastIndex] += Array[LastIndex + 1];
                steps++;
            }

            // merge other two elements
            else
            {
                ++FrontIndex;
                Array[FrontIndex] += Array[FrontIndex - 1];
                steps++;
            }
        }
        return steps;
    }
};

int main()
{
    vector<int> v = {6, 5, 6, 5, 5, 5};

    Solution ON;
    cout << ON.FindMinSteps(v) << endl;
    return 0;
}