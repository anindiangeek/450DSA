/*
    * https://practice.geeksforgeeks.org/problems/common-elements1132/1

    * https://www.geeksforgeeks.org/find-common-elements-three-sorted-arrays/
*/

#include <bits/stdc++.h>
using namespace std;

class BetterApproach // o(n1 +n2 +n3) & s(1)
{
  public:
    vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
    {
        vector<int> answer;
        int index1 = 0, index2 = 0, index3 = 0;
        int PreviousValue1 = INT_MIN, PreviousValue2 = INT_MIN, PreviousValue3 = INT_MIN;

        while (index1 < n1 && index2 < n2 && index3 < n3)
        {
            // if the value of previous element is same and index1 is still in bound keep incrimenting.
            while (A[index1] == PreviousValue1 && index1 < n1)
                ++index1;
            while (B[index2] == PreviousValue2 && index2 < n2)
                ++index2;
            while (C[index3] == PreviousValue3 && index3 < n3)
                ++index3;

            if (A[index1] == B[index2] && B[index2] == C[index3])
            {
                answer.push_back(A[index1]);
                PreviousValue1 = A[index1];
                PreviousValue2 = A[index2];
                PreviousValue3 = A[index3];
                ++index1;
                ++index2;
                ++index3;
            }

            else if (A[index1] < B[index2])
            {
                PreviousValue1 = A[index1];
                ++index1;
            }

            else if (B[index2] < C[index3])
            {
                PreviousValue2 = B[index2];
                ++index2;
            }

            else
            {
                PreviousValue3 = C[index3];
                ++index3;
            }
        }

        return answer;
    }
};

class Solution // TC O(n1logn2) + common elements be in n1 and n2 * log(n3))
{
    // this will be clearly larger than O(N1 + N2 + N3)
    // also we have to use additional data structure for repettive values.
    // finding Intersection through binary search.
  public:
    vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
    {
        vector<int> v;
        for (int i = 0; i < n1; ++i)
            if (binary_search(B, B + n2, A[i]))
                v.push_back(A[i]);

        set<int> ans;
        for (int i = 0; i < v.size(); i++)      //
            if (binary_search(C, C + n3, v[i])) // log(n3)
                ans.insert(v[i]);               // log(n)
        v.clear();

        vector<int> a;
        for (auto it = ans.begin(); it != ans.end(); it++)
            a.push_back(*it);
        return a;
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("C://450DSA//i.txt", "r", stdin);
    freopen("C://CP//e.txt", "w+", stderr);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];

        for (int i = 0; i < n1; i++)
            cin >> A[i];
        for (int i = 0; i < n2; i++)
            cin >> B[i];
        for (int i = 0; i < n3; i++)
            cin >> C[i];

        Solution ob;

        vector<int> res = ob.commonElements(A, B, C, n1, n2, n3);
        if (res.size() == 0)
            cout << -1;
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
}