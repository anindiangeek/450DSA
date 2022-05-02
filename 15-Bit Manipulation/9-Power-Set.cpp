/*
    Problem : Given a string S find all possible subsequences of the string in lexicographically-sorted order.



    Problem Link : https://practice.geeksforgeeks.org/problems/power-set4302/1
                https://www.geeksforgeeks.org/recursive-program-to-generate-power-set/
*/

#include <bits/stdc++.h>
using namespace std;

class UsingBitManipulation // O(2^(length of string))
{
    /*
        Set  = [a,b,c]
        power_set_size = pow(2, 3) = 8
        Run for binary counter = 000 to 111

        Value of Counter            Subset
           000                    -> Empty set
           001                    -> a
           010                    -> b
           011                    -> ab
           100                    -> c
           101                    -> ac
           110                    -> bc
           111                    -> abc
    */

  public:
    vector<string> AllPossibleStrings(string s)
    {
        vector<string> answer;
        int n = s.length();
        for (int i = 1; i < (1 << n); i++) // from 1 to 2^n
        {
            string sub = "";
            for (int j = 0; j < n; j++)
                if (i & 1 << j) // if ith bit is set include it in empty string.
                    sub += s[j];
            answer.push_back(sub);
        }
        sort(answer.begin(), answer.end()); // asnwer was asked in lexographically order.
        return answer;
    }
};
class UsingSTL
{
    /*
     * In auxiliary array of bool set all elements to 0.
     * That represent an empty set.
     * Set first element of auxiliary
     * array to 1 and generate all permutations to produce all subsets with one element.
     * Then set the second element to 1 which will produce all subsets with two elements,
     * repeat until all elements are included.
     */
  public:
    vector<string> printPowerSet(string set, int n)
    {
        bool *contain = new bool[n]{0};
        vector<string> ans;
        for (int i = 0; i < n; i++)
        {
            contain[i] = 1;
            // All permutation
            do
            {
                string s = "";
                for (int j = 0; j < n; j++)
                    if (contain[j])
                        s += set[j];
                ans.push_back(s);
            } while (prev_permutation(contain, contain + n));
            // learn more about std::prev_permutation
            // https://www.geeksforgeeks.org/stdnext_permutation-prev_permutation-c/
            // https://en.cppreference.com/w/cpp/algorithm/prev_permutation
        }
        return ans;
    }
};

class UsingRecursion // O(2^(length of string)) or backtracking //pending 
{
  public:
    vector<string> AllPossibleStrings(string s)
    {
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string s;
        cin >> s;
        // UsingBitManipulation ob;
        UsingSTL ob2;
        // vector<string> res = ob.AllPossibleStrings(s);
        vector<string> res = ob2.printPowerSet(s, s.length());
        for (auto i : res)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}