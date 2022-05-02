/*
    Problem : Given a dividend and a divisor, output the result without using multiplication, modlus %, or / divison
   operator.

    Explantion : quotient of a division is just the number of times that we can subtract the divisor from the dividend
   without making it negative.

    Related Links :
    * https://leetcode.com/problems/divide-two-integers/discuss/1516367/Complete-Thinking-Process-or-Intuitive-Explanation-or-All-rules-followed-or-C%2B%2B-code

    Problem Links :
     * https://practice.geeksforgeeks.org/problems/division-without-using-multiplication-division-and-mod-operator/1/
     * https://leetcode.com/problems/divide-two-integers/

*/

#include <bits/stdc++.h>
using namespace std;

class UsingSubStractionOperator // O(dividend/divisor)
{
  public:
    long long divide(long long dividend, long long divisor)
    {
        if (dividend == divisor)
            return 1ll;
        // if any of the number is negative or then we will have a negative answer.
        // checking if they have same sign then they will not have signed answer.
        bool NotSign = (dividend < 0) == (divisor < 0);

        dividend = abs(dividend);
        divisor = abs(divisor);

        long long answer{0};

        while (dividend >= divisor)
        {
            dividend -= divisor;
            answer++;
        }
        return !NotSign ? -1ll * answer : answer;
    }
};

class UsingBitManuplution
{
  public:
    long long divide(long long dividend, long long divisor)
    {

        if (dividend == divisor)
            return 1ll;
        if (divisor == 1)
            return dividend;

        // if any of the number is negative or then we will have a negative answer.
        // checking if they have same sign then they will not have signed answer.
        bool NotSign = (dividend < 0) == (divisor < 0);

        // removing sign
        unsigned int Newdividend = abs(dividend);
        unsigned int Newdivisor = abs(divisor);

        long long quotient{0};

        while (Newdividend >= Newdivisor)
        {
            long long NearestPowerOf2{0};

            // finding the neareast power of two for which divisor becomes greater than dividend.

            while (Newdividend > (Newdivisor << NearestPowerOf2 + 1))
                NearestPowerOf2++;

            quotient += (1 << NearestPowerOf2);             // adding 2^Nearpowerof2 to the answer;
            Newdividend -= (Newdivisor << NearestPowerOf2); // removing the neareast power 2 from the answer.
        }

        // return the answer after adding the sign to it if required.
        return !NotSign ? -1ll * quotient : quotient;
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {

        long long a, b;
        cin >> a >> b;

        UsingSubStractionOperator ob;

        cout << ob.divide(a, b) << "\n";
    }

    return 0;
}
