/*
    if the order of appreance has to be maintained.
    * https://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/
    if the relative order is not important.
    * https://www.geeksforgeeks.org/rearrange-array-in-alternating-positive-negative-items-with-o1-extra-space-set-2/

    * as the problem is easy if we are allowed to use extra space but we will do it without using extra space.
 */

#include <bits/stdc++.h>
using namespace std;

void Print(int a[], int size)
{
    for (int i = 0; i < size; i++)
        cerr << a[i] << " ";
    cerr << endl;
}

class OrderNotImportant // O(N) & S(1)
{
    // there are 2 approaches for the same.
    // both does not maintain the relative order of numbers.

    /* O(NlogN) Solution.
     * Count the number of Positives & Negatives.
     * Sort The array.
     * According the number we can re-arrange the values in alternating fashion.
     */

    /* O(N) Solution.
     * Shift all the negative numbers to end.
     * Use Two-Pointers to swap the alternate places.
     */
  public:
    void Rearrange(int a[], int size)
    {
        int i = 0, j = size - 1;

        // moving all the negative to one side.
        while (i < j)
        {
            // continue moving i till we keep getting positive values.
            while (i <= size - 1 && a[i] >= 0)
                i++;
            // continue moving j till we keep getting Negative values.
            while (j >= 0 && a[j] < 0)
                j--;
            // if this condition holds swap the values.
            if (i < j)
                swap(a[i], a[j]);
        }

        // if there are only negative values or only positive values, return.
        // i will be at 0 if there are only -ve val and vice versa.
        if (i == 0 or i == size)
            return;

        int k = 0;
        while (k < size && i < size)
        {
            // swap next positive
            // element at even position
            // from next negative element.
            swap(a[k], a[i]);
            i = i + 1;
            k = k + 2;
        }
    }
};

class MaintainRelativeOrder // O(n^2)  S(1)
{
    /*
        The idea is to process array from left to right. While processing, find the first out of place element in the
       remaining unprocessed array. An element is out of place if it is negative and at odd index (0 based index), or it
       is positive and at even index (0 based index) . Once we find an out of place element, we find the first element
       after it with opposite sign. We right rotate the subarray between these two elements (including these two).
    */
  public:
    bool IsEven(int Number)
    {
        if (Number & 0x01)
            return false;
        return true;
    }

    void Rotate(int a[], int size, int OutOfPlaceIndex, int CurrentIndex)
    {
        int temp = a[CurrentIndex];
        for (int i = CurrentIndex; i > OutOfPlaceIndex; i--)
            a[i] = a[i - 1];
        a[OutOfPlaceIndex] = temp;
        Print(a, size);
    }

    void Rearrange(int a[], int size)
    {
        int OutOfPlaceIndex = -1;

        for (int Index = 0; Index < size; Index++)
        {
            if (OutOfPlaceIndex >= 0)
            {

                // Index & OutOfIndex should be distinct pairs. [pos. . . .neg] || [neg .... pos]
                //                                                 ^       ^         ^        ^
                //                                                 OOI      I        OOI      I
                if ((a[Index] >= 0 && a[OutOfPlaceIndex] < 0) || (a[Index] < 0 && a[OutOfPlaceIndex] >= 0))
                {
                    cerr << endl << "Out of place Index : " << OutOfPlaceIndex << " Current Index : " << Index << endl;
                    cerr << "Rotating : [" << OutOfPlaceIndex << "," << Index << "]" << endl << endl;
                    Rotate(a, size, OutOfPlaceIndex, Index);

                    // the new out-of-place entry is now 2 steps
                    // ahead
                    if (Index - OutOfPlaceIndex >= 2)
                        OutOfPlaceIndex += 2;
                    else
                        OutOfPlaceIndex = -1;
                }
            }

            if (OutOfPlaceIndex == -1)
            {
                // conditions for index to be out of place
                if ((a[Index] >= 0 && IsEven(Index)) || (a[Index] < 0 && !IsEven(Index)))
                    OutOfPlaceIndex = Index;
            }
        }
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
    // int a[] = {3, 5, 4, -1, 0, -5, -7, -1, 9, -8};
    int a[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    int size = sizeof(a) / sizeof(int);

    cerr << "Input is : " << endl;
    Print(a, size);

    MaintainRelativeOrder ON2;

    ON2.Rearrange(a, size);
    cerr << endl << "Final Answer is : " << endl;
    Print(a, size);

    return 0;
}