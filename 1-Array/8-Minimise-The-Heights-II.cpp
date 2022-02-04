/*
    https: // practice.geeksforgeeks.org/problems/minimize-the-heights3351/1

    * Can be solved using normal greedy apporach.
    * without using extra space.
    * We will sort the array and keep the inital result as difference.
    * for any element in middle say x and its right value y
    	we have ro minimize the range if we plot them on number line so all the elements on left will be added k in them
        and all the element in right we will sub k with them.
        and update the smallest and largest and will keep the result.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution //O(nlogn)
{
  public:
    int getMinDiff(int a[], int n, int k)
    {
        sort(a, a + n); //O(nlogn)

        int mini, maxi, result = a[n - 1] - a[0];
        int smallest = a[0] + k;
        int largest = a[n - 1] - k;

        for (int i = 1; i < n; i++)
        {
            mini = min(smallest, a[i] - k);
            maxi = max(largest, a[i - 1] + k);
            if (mini < 0) // to avoid negatives.
                continue;
            result = min(result, maxi - mini);
        }


        return result;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}