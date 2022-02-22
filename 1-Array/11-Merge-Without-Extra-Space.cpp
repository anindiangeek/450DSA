#include <bits/stdc++.h>
using namespace std;
int arr1[4], arr2[5];

class GapUsingShellSort // O(N+ M)
{
  public:

    int nextgap(int gap)
    {
        if (gap <= 1)
            return 0;
        return (gap / 2) + (gap % 2); // returns the ceil value.
    }

    void merge(int n, int m)
    {
        int i = 0, j, gap = n + m;

        for (gap = nextgap(gap); gap > 0; gap = nextgap(gap))
        {

            // IF THEY ARE IN SAME FIRST ARRAY.
            for (i = 0; i < n - gap; i++)
                if (arr1[i] > arr1[i + gap])
                    swap(arr1[i], arr1[i + gap]);

            // if they are in seperate arrays.

            for (j = (gap > n) ? gap - n : 0; i < n && j < m; i++, j++)
                if (arr1[i] > arr2[j])
                    swap(arr1[i], arr2[j]);

            // after this there are still elements left in the gap.
            // both pointers are in second array.
            if (j < m)
                for (j = 0; j + gap < m; j++)
                    if (arr2[j] > arr2[j + gap])
                        swap(arr2[j], arr2[j + gap]);
        }
    }

};

class ObservationSolution // O((m+n)log(n+m))
{
    /*
        The solution can be further optimized by observing that while traversing the two sorted arrays parallelly, if we
       encounter the jth second array element is smaller than ith first array element, then jth element is to be
       included and replace some kth element in the first array. This observation helps us with the following algorithm
     */
  public:
    void merge(int arr1[], int arr2[], int n, int m)
    {
        int i = 0, j = 0, k = n - 1;
        while (i <= k && j < m)
        {
            if (arr1[i] > arr2[j])
                i++;
            else
                swap(arr2[j++], arr1[k--]);
        }
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);
    }
};

class MergeWithoutExtraSpace // O(n * m) && S(1)
{

    // using insertion sort as a sub-routine.
    // using two pointer to comapre and swap then sort the second list in O(N) using insertion sort.

  private:
    void merge(int arr1[], int arr2[], int n, int m)
    {
        for (int i = m - 1; i >= 0; i--) // iterating though all the values of 2nd list.
        {

            // we will insert (sort) the arr2[i] in arr1. we will save last value of arr1.

            int j = n - 2, last = arr1[n - 1];

            while (j >= 0 && arr1[j] > arr2[i])
            {
                arr1[j + 1] = arr1[j];
                j--;
            }

            if (j != n - 2 || last > arr2[i])
            {
                arr1[j + 1] = arr2[i];
                arr2[i] = last;
            }
        }
    }
};


//Refer to the merge function of Merge Sort to understand this

class ExtraSpaceAllowed // O(N+M) & S(N+M)
{
  public:
    void merge(int arr1[], int arr2[], int n, int m)
    {
        int extra[n + m], i = 0, j = 0, k = 0;
        while (i < n && j < m)
        {
            if (arr1[i] < arr2[j])
                extra[k++] = arr1[i++];
            else
                extra[k++] = arr2[j++];
        }
        while (i < n)
            extra[k++] = arr1[i++];

        while (j < m)
            extra[k++] = arr2[j++];

        for (int i = 0; i < n; i++)
            extra[i] = arr1[i];
        for (int i = 0, j = n; i < m; i++)
            extra[j++] = arr2[i];
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("i.txt", "r", stdin);
    freopen("e.txt", "w+", stderr);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, i;
        cin >> n >> m;
        // int arr1[n], arr2[m];
        for (i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }
        GapUsingShellSort ob;
        ob.merge(n, m);
        for (i = 0; i < n; i++)
        {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++)
        {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends