/*
    * Question : https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

    * Dutch National flag algorithm.
        -> we use this same algorithm in 3 Way Quick-Sort where there are a lot of similar elements.

    * read more about it here :https://en.wikipedia.org/wiki/Dutch_national_flag_problem
    * we could have used count sort to to solve this in O(n) time but as the space constraint is O(1)
      we have to use this.
*/

#include <bits/stdc++.h>
using namespace std;

class DNFAlgorithm
{
  public:
    void sort012(int a[], int n)
    {
        int low = 0, mid = 0, high = n - 1, i = 0;
        // we sort the array in single scan i.e o(n);
        while (mid <= high)
        {
            switch (a[i])
            {
            case 0:
                swap(a[low], a[i]);
                // notice no break in here. guess why?
            case 1:
                mid++;
                break;
            case 2:
                swap(a[i--], a[high--]);
                break;
            }
            i++;
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

        DNFAlgorithm ob;
        ob.sort012(a, n);

        for (int i = 0; i < n; i++)
            cout << a[i] << " ";

        cout << endl;
    }
    return 0;
}