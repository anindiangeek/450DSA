/*
    Problem :
    * https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

    Not recemmonded but here is a resourse
    *  http://staff.ustc.edu.cn/~csli/graduate/algorithms/book6/chap10.htm

*/
#include <bits/stdc++.h>
using namespace std;

class MeanOrderStastics
{
    // to gaurrantee that it will not be the worst case in case of quick select
    // :https://www.youtube.com/watch?v=fcf56RTbkHc
    // source code for this class :
    // https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-3-worst-case-linear-time/?ref=lbp
  public:
    int findMedian(int arr[], int n)
    {
        sort(arr, arr + n);
        return arr[n / 2]; // returning the middle element(Median) after sorting.
    }

    int partition(int arr[], int Left, int Right, int k)
    {
        // we will search for the k in here.
        int i;
        for (i = Left; i < Right; i++)
            if (arr[i] == k)
                break;
        swap(arr[i], arr[Right]);

        // we will now make a partition around k.
        i = Left;
        for (int j = Left; j <= Right - 1; j++)
        {
            if (arr[j] <= k)
            {
                swap(arr[i], arr[j]);
                i++;
            }
        }
        swap(arr[i], arr[Right]);
        return i;
    }

    int QuickSelect(int arr[], int Left, int Right, int k)
    {
        // If k is smaller than number of elements in array
        if (k > 0 && k <= Right - Left + 1)
        {
            int n = Right - Left + 1; // Number of elements in arr[Left..Right]

            // Divide arr[] in groups of size 5, calculate median
            // of every group and store it in median[] array.
            int i, median[(n + 4) / 5]; // There will be floor((n+4)/5) groups;
            for (i = 0; i < n / 5; i++)
                median[i] = findMedian(arr + Left + i * 5, 5);
            if (i * 5 < n) // For last group with less than 5 elements
            {
                median[i] = findMedian(arr + Left + i * 5, n % 5);
                i++;
            }

            // Find median of all medians using recursive call.
            // If median[] has only one element, then no need
            // of recursive call
            int medOfMed = (i == 1) ? median[i - 1] : kthSmallest(median, 0, i - 1, i / 2);

            // Partition the array around a random element and
            // get position of pivot element in sorted array
            int pos = partition(arr, Left, Right, medOfMed);

            // If position is same as k
            if (pos - Left == k - 1)
                return arr[pos];
            if (pos - Left > k - 1) // If position is more, recur for left
                return QuickSelect(arr, Left, pos - 1, k);
            else
                // Else recur for right subarray
                return QuickSelect(arr, pos + 1, Right, k - pos + Left - 1);
        }

        // If k is more than number of elements in array
        return INT_MAX;
    }
    int kthSmallest(int arr[], int Left, int Right, int k)
    {
        return QuickSelect(arr, Left, Right, k);
    }
};

// using Quick- select with Random partition.
// we could have used normal partiton but that will result in TLE as it can go through the worst case.

class QuickSelectwithRandomPartition
{
  public:
    void randompartition(int arr[], int Left, int Right)
    {
        int pivot = rand() % (Right - Left + 1);
        swap(arr[Left + pivot], arr[Right]);
    }

    int Partition(int arr[], int Left, int Right)
    {
        randompartition(arr, Left, Right);

        int pivot = arr[Right], j = Left;

        for (int i = Left; i <= Right - 1; i++)
            if (arr[i] <= pivot)
                swap(arr[i], arr[j++]);

        swap(arr[j], arr[Right]);

        return j;
    }

    int QuickSelect(int arr[], int Left, int Right, int k)
    {
        if (k > 0 && k <= Right - Left + 1)
        {
            int p = Partition(arr, Left, Right);

            if (p - Left == k - 1)
                return arr[p];

            if (p - Left > k - 1)
                return QuickSelect(arr, Left, p - 1, k);
            else
                return QuickSelect(arr, p + 1, Right, k - p + Left - 1);
        }

        return INT_MAX;
    }

    int kthSmallest(int arr[], int Left, int Right, int k)
    {
        return QuickSelect(arr, Left, Right, k);
    }
};

int main()
{
    int test_case;
    cin >> test_case;
    while (test_case--)
    {
        int number_of_elements;
        cin >> number_of_elements;
        int a[number_of_elements];

        for (int i = 0; i < number_of_elements; i++)
            cin >> a[i];

        int k;
        cin >> k;
        QuickSelectwithRandomPartition ob;
        cout << ob.kthSmallest(a, 0, number_of_elements - 1, k) << endl;
    }
    return 0;
}