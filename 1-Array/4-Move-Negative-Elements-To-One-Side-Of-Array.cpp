/*
    https://practice.geeksforgeeks.org/problems/move-all-negative-elements-to-end1813/1#

    O(n) & S(n);
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    void segregateElements(int arr[], int n)
    {
        list<int> PositiveList, NegativeList;
        int CurrentIndex = 0;
        for (; CurrentIndex < n; CurrentIndex++)
        {
            if (arr[CurrentIndex] >= 0)
                PositiveList.push_back(arr[CurrentIndex]);
            else
                NegativeList.push_back(arr[CurrentIndex]);
        }

        for (CurrentIndex = 0; PositiveList.empty() != true; CurrentIndex++)
        {
            arr[CurrentIndex] = PositiveList.front();
            PositiveList.pop_front();
        }

        for (; NegativeList.empty() != true; CurrentIndex++)
        {
            arr[CurrentIndex] = NegativeList.front();
            NegativeList.pop_front();
        }
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
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        ob.segregateElements(a, n);

        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}