/*
    * https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/

    * Using STL
    * Normal Iterative Method.
    * => Using recursion & tournament Method i.e in less number of comparisons.
*/

#include <bits/stdc++.h>
using namespace std;

// finding maximum element using recursion.

int MaxElement(int a[], int size)
{
    static int Max = INT_MIN;
    if (size == 0)
        return Max;
    if (a[size - 1] > Max)
        Max = a[size - 1];
    return MaxElement(a, size - 1);
}

// we can optimise this recursive solution by making less comparisons.
pair<int, int> TournamentMethod(int a[], int low, int high)
{

    pair<int, int> Left, Right, final;

    if (low == high)
        return {a[high], a[high]};

    else if (high - low == 1)
    {
        if (a[high] > a[low])
            return {a[high], a[low]};
        else
            return {a[low], a[high]};
    }

    else
    {
        int mid = (low + high) / 2;

        Left = TournamentMethod(a, low, mid);
        Right = TournamentMethod(a, mid, high);

        final.second = min(Left.second, Right.second);
        final.first = max(Left.first, Right.first);

        return final;
    }
}

// using STL to find Minimum & Maximum element.
pair<int, int> MaxAndMinElement(int a[], int size)
{
    return {*max_element(a, a + size), *min_element(a, a + size)};
    // as it is cleary unserstandble by the names of the functions, they return a pointer pointing to the Max & min
    // element in a container
}

int main()
{
    int a[] = {6, 7, 8, 8, 9, 5, 12, 3, 4, 1, 3, 4, -6, -44};
    int size = sizeof(a) / sizeof(int);
    cout << TournamentMethod(a, 0, size - 1).first << " " << TournamentMethod(a, 0, size - 1).second << endl;
    cout << MaxElement(a, size) << endl;
    cout << MaxAndMinElement(a, size).first << " " << MaxAndMinElement(a, size).second << endl;
}