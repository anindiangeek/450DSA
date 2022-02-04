/*
    * https://practice.geeksforgeeks.org/problems/array-subset-of-another-array2317/1

    * Solution : https://www.geeksforgeeks.org/find-whether-an-array-is-subset-of-another-array-set-1/


*/

#include <bits/stdc++.h>
using namespace std;

class HasingSolution
{
    // it is effecient to store larger array and check if the element is in has for another array.
  public:
    string isSubset(int a1[], int a2[], int n, int m)
    {
        unordered_set<int> Hash;

        for (int i = 0; i < n; i++)
            Hash.insert(a1[i]);

        for (int i = 0; i < m; i++)
            if (Hash.find(a2[i]) == Hash.end())
                return "No";

        return "Yes";
    }
};

class NaiveSolution
{
    // the naive solution according ot me is to sort one array and do the binary search for the smaller array.
  public:
    string isSubset(int a1[], int a2[], int n, int m)
    {
        sort(a1, a1 + n);
        for (int i = 0; i < m; i++)
            if (!binary_search(a1, a1 + n, a2[i]))
                return "No";
        return "Yes";
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
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];

        for (int i = 0; i < n; i++)
            cin >> a1[i];
        for (int i = 0; i < m; i++)
            cin >> a2[i];
        NaiveSolution NLOGN;
        cout << NLOGN.isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}