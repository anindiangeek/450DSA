/*
    https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1

    * using sets Extra space then we can do it in O(n+m).
    * we use binary search and other algorihtms to do without extra space.

    you can read more about it here : https://www.geeksforgeeks.org/find-union-and-intersection-of-two-unsorted-arrays/
*/

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
int r()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
}
static int p = r();
class Solution
{
  public:
    // Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)
    {
        set<int> s;
        for (int i = 0; i < n; i++)
            s.insert(a[i]);
        for (int j = 0; j < m; j++)
            s.insert(b[j]);

        return s.size();
    }
};

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int n, m;
        cin >> n >> m;
        int a[n], b[m];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < m; i++)
            cin >> b[i];
        Solution ob;
        cout << ob.doUnion(a, n, b, m) << endl;
    }

    return 0;
}