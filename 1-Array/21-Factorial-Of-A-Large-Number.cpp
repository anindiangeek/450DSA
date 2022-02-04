/*
 *	https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1

 * while you reapeat this see this as well
    https://www.geeksforgeeks.org/factorial-of-large-numbers-using-logarithmic-identity/?ref=lbp
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    void Multiply(vector<int> &v, int Number)
    {
        int carry = 0;
        for (int i = 0; i < v.size(); i++)
        {
            int Answer = v[i] * Number + carry;

            v[i] = Answer % 10;

            carry = Answer / 10;
        }

        while (carry)
        {
            v.push_back(carry % 10);
            carry /= 10;
        }
    }
    vector<int> factorial(int N)
    {
        vector<int> v;
        v.push_back(1);
        for (int i = 2; i < N; i++)
            Multiply(v, i);

        reverse(v.begin(), v.end());
        return v;
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
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        Solution ob;
        vector<int> result = ob.factorial(N);

        for (int i = 0; i < result.size(); ++i)
            cout << result[i];
        cout << endl;
    }
    return 0;
}
