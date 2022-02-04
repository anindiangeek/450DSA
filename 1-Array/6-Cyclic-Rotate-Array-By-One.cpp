/*
    https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1

    * easy problem we can also it by replacing the values and saving it in a temp variable.
        temp<-a[n-1];
        for n-1->0
            a[i]<-a[i-1];
        a[0]<-temp;
*/

#include <bits/stdc++.h>
using namespace std;

void rotate(int arr[], int n)
{
    for (int i = n - 1; i > 0; i--)
        swap(arr[i - 1], arr[i]);
}