#include <bits/stdc++.h>
using namespace std;

/*
    Problem : Given N, return N^2 without using multiplication, divison operator or power function.

    Explanation : https://www.geeksforgeeks.org/calculate-square-of-a-number-without-using-and-pow/
*/

class UsingAddition // O(N) S(1)
{
  public:
    int power(int N)
    {
        // if the given number is negative then we make it positive as the square of will be postitve only.
        if (N < 0)
            N = -N;

        int Square{0};
        for (int i = 0; i < N; i++)
            Square += N;

        return Square;
    }
};

class UsingBitManipulation // O(logN)
{
    /*
        square(n) = 0 if n == 0
    if n is even
        square(n) = 4*square(n/2)
    if n is odd
     square(n) = 4*square(floor(n/2)) + 4*floor(n/2) + 1

    Examples
        square(6) = 4*square(3)
        square(3) = 4*(square(1)) + 4*1 + 1 = 9
        square(7) = 4*square(3) + 4*3 + 1 = 4*9 + 4*3 + 1 = 49

        If n is even, it can be written as
            n = 2*x
            n2 = (2*x)2 = 4*x2
        If n is odd, it can be written as
            n = 2*x + 1
            n2 = (2*x + 1)2 = 4*x2 + 4*x + 1
    */
  public:
    int power(int N)
    {
        if (N == 0)
            return 0;
        if (N < 0)
            N = -N;

        int x = N >> 1; // equivalent to floor(N/2)

        if (N & 1) // if odd
            return ((power(x) << 2) + x << 2 + 1);
        else
            return (power(x) << 2);
    }
};
class BitManipulation2 // log(N)
{
    /*
        For a given number `num` we get square of it by multiplying number as `num * num`.
        Now write one of `num` in square `num * num` in terms of power of `2`. Check below examples.

        Eg: num = 10, square(num) = 10 * 10
                                  = 10 * (8 + 2) = (10 * 8) + (10 * 2)
            num = 15, square(num) = 15 * 15
                                  = 15 * (8 + 4 + 2 + 1) = (15 * 8) + (15 * 4) + (15 * 2) + (15 * 1)

        Multiplication with power of 2's can be done by left shift bitwise operator.
    */
  public:
    int square(int num)
    {
        // handle negative input
        if (num < 0)
            num = -num;

        int result = 0, times = num;

        while (times > 0)
        {
            int possibleShifts = 0, currTimes = 1;

            while ((currTimes << 1) <= times)
            {
                currTimes = currTimes << 1;
                ++possibleShifts;
            }

            result = result + (num << possibleShifts);
            times = times - currTimes;
        }

        return result;
    }
};

class BitManipulation3 // log(N)
{
  public:
    int square(int num)
    {
        if (num < 0)
            num = -num;

        int result{0}, power{0}, temp{num};

        while (temp)
        {
            // is odd
            if (temp & 1)
                result += (num << power);
            power++;

            temp = temp >> 1; // temp=temp/2;
        }
        return result;
    }
};

int main()
{
    // UsingAddition ob;
    BitManipulation3 ob;
    // cout << ob.power(10) << endl;
    cout << ob.square(5) << endl;
}