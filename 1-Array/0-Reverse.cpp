/*
 * Program to reverse any structure.
 * reverse using recursion.
 * Iterative method to reverse.
 * use of STL reverse() function.
 * we use two pointers method to reverse a list without using extra space.
 */

#include <bits/stdc++.h>
using namespace std;

// reverse using recursion.
void RecurrsionReverse(int a[], int leftIndex, int RightIndex)
{
    if (leftIndex >= RightIndex)
        return;
    swap(a[leftIndex], a[RightIndex]);
    RecurrsionReverse(a, leftIndex + 1, RightIndex - 1);
}

// reverse using STL

void STLReverse(int a[], int size)
{
    // we can reverse vectors, arrays, lists, anything container using reverse.
    // we have to mention first and last iterators to reverse it.

    // vectors and similar containers in STL
    // reverse({container_name}.begin(),{container_name}.end()) is used to reverse the entire container.
    // to reverse till a specfic segment we have to define an iterator to taht location or we can use
    // {container_name.begin()+ n} where n belongs to int class.

    reverse(a, a + size);

    // we use this for normal arrays, this also works for string, we can use .begin() in strings as well.
}

void IterativeReverse(int a[], int size)
{
    size_t LeftIndex = 0, RightIndex = size - 1;
    // using inbuilt swap function.
    while (LeftIndex <= RightIndex)
        swap(a[LeftIndex++], a[RightIndex--]);
}