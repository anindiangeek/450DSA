/*
    https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1#

    * Use only this procedure for it no other remeber this make two different sized array only that gets AC.

    * https://www.youtube.com/watch?v=kQ1mJlwW-c0 // for understanding.
    * Do not copy the above code showm in video.


*/

#include <bits/stdc++.h>
using namespace std;

class Solution // O(nlogn)  S(N)
{
    long long Merge(long long arr[], long long low, long long mid, long long high)
    {
        long long inv = 0;
        long long Length1 = mid - low + 1;
        long long Length2 = high - mid;
        long long first[Length1];
        long long second[Length2];

        int k = low;
        for (int i = 0; i < Length1; i++)
            first[i] = arr[k++];
        k = mid + 1;
        for (int i = 0; i < Length2; i++)
            second[i] = arr[k++];

        long long itr1 = 0, itr2 = 0;
        k = low;

        while (itr1 < Length1 && itr2 < Length2)
        {
            if (first[itr1] <= second[itr2])
                arr[k++] = first[itr1++];
            else
            {
                arr[k++] = second[itr2++];
                inv += Length1 - itr1;
            }
        }

        while (itr1 < Length1)
            arr[k++] = first[itr1++];
        while (itr2 < Length2)
            arr[k++] = second[itr2++];

        return inv;
    }
    long long MergeSort(long long arr[], long long low, long long high)
    {
        long long inverse_count = 0;
        if (low < high)
        {
            long long mid = (low + high) / 2;

            inverse_count += MergeSort(arr, low, mid);
            inverse_count += MergeSort(arr, mid + 1, high);

            inverse_count += Merge(arr, low, mid, high);
        }
        return inverse_count;
    }

  public:
    long long inversionCount(long long arr[], long long N)
    {
        return MergeSort(arr, 0, N - 1);
    }
};

int main()
{
    long long T;
    cin >> T;
    while (T--)
    {
        long long N;
        cin >> N;
        long long A[N];
        for (long long i = 0; i < N; i++)
            cin >> A[i];
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }
    return 0;
}