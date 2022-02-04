#include <bits/stdc++.h>
using namespace std;

/*
    //Problem Link was not found:
    Problem: Given two sorted arrays of "same size", find their median
    Median : middle most value(s).
    as the arrays are of same size,total size will be 2N,So there will be two medians, return their average.

     A[]  {1,5,6,8,9,21,32};
     B[]  {2,3,5,7,11,12,21};

     Expected T.C O(log(N+M))
     Expected T.C O(1)

    Solution and Explanation
    * https://www.geeksforgeeks.org/median-of-two-sorted-arrays/
*/

class DACSolution // O(LogN) & //stack space
{
  public:
    int median(int Array[], int size)
    {
        if (size & 1)
            return Array[size / 2];

        return (Array[size / 2] + Array[(size / 2) + 1]) / 2;
    }

    int DAC(int FirstArray[], int SecondArray[], int size)
    {
        if (size <= 0)
            return -1;
        if (size == 1)
            return (FirstArray[0] + SecondArray[0]) / 2;
        if (size == 2)
            return (max(FirstArray[0], SecondArray[0]) + min(FirstArray[1], SecondArray[1])) / 2;

        int Median1 = median(FirstArray, size);
        int Median2 = median(SecondArray, size);

        if (Median1 == Median2)
            return Median1;
        else if (Median1 > Median2)
        {
            if (size % 2 == 0)
                return DAC(SecondArray + size / 2 - 1, FirstArray, size - ((size / 2) + 1));
            return DAC(SecondArray + size / 2, FirstArray, size - (size / 2));
        }

        else
        {
            if (size % 2 == 0)
                return DAC(FirstArray + size / 2 - 1, SecondArray, size - ((size / 2) + 1));
            return DAC(FirstArray + size / 2, SecondArray, size - (size / 2));
        }
    }
    int MedianOfSameSize(int FirstArray[], int SecondArray[], int size)
    {
        return DAC(FirstArray, SecondArray, size);
    }
};

class BetterNaiveSolution // O(N)
{
    /*
        Idea is to use same algorithm as merging but do not use extra sapce but to keep count of elements total
        processed.

        if the elements total processed are N, then we will return the average of N & N-1 element.
    */

  public:
    int MedianOfSameSize(int FirstArray[], int SecondArray[], int size)
    {

        int count = 0, i = 0, j = 0, Median = 0;

        for (count = 1; count <= size; count++)
        {
            if (FirstArray[i] <= SecondArray[j])
                Median = FirstArray[i++];
            else
                Median = SecondArray[j++];
        }

        if (FirstArray[i] <= SecondArray[j])
            Median += FirstArray[i];
        else
            Median += SecondArray[j];

        return Median / 2;
    }
};

class NaiveSolution // O(2*N) & S(2*N)
{
    // Merging both arrays and returing the median.
  public:
    int MedianOfSameSize(int FirstArray[], int SecondArray[], int size)
    {
        int Median = 0, i = 0, j = 0, k = 0;
        int ExtraSpace[size + 1];

        while (k <= size && i < size && j < size)
        {

            if (FirstArray[i] <= SecondArray[j])
                ExtraSpace[k++] = FirstArray[i++];

            else
                ExtraSpace[k++] = SecondArray[j++];
        }

        while (k <= size && i < size)
            ExtraSpace[k++] = FirstArray[i++];
        while (k <= size && j < size)
            ExtraSpace[k++] = SecondArray[j++];

        Median = (ExtraSpace[size] + ExtraSpace[size - 1]) / 2;

        return Median;
    }
};

int main()
{
    int FirstArray[] = {1, 12, 15, 26, 38};
    int SecondArray[] = {2, 13, 17, 30, 45};

    int size = sizeof(SecondArray) / sizeof(int);

    // NaiveSolution O2N;
    // BetterNaiveSolution O2N;
    DACSolution LOGN;
    // cout << O2N.MedianOfSameSize(FirstArray, SecondArray, size) << endl;
    cout << LOGN.MedianOfSameSize(FirstArray, SecondArray, size) << endl;
    return 0;
}