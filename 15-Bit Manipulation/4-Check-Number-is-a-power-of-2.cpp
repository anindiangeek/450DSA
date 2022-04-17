/*
	Problem: Given a Number N tell if it is a power of 2.

	* A number which is a power of 2 is in the form 10000...
	* so we just have to count the number of set bits in it's binary reprsentation.

	Problem Link : https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/1#
	Solution & Explanations : https://www.geeksforgeeks.org/program-to-find-whether-a-given-number-is-power-of-2/
*/

#include <bits/stdc++.h>
using namespace std;

class UsingCountSetBitsQuestionLogic // O(1)
{
	/*
		If we subtract a power of 2 numbers by 1 then all unset bits after the only set bit become set; and the set bit becomes unset.
		For example for 4 ( 100) and 16(10000), we get the following after subtracting 1
		3 	–> 011
		15  –> 01111
		So, if a number n is a power of 2 then bitwise & of n and n-1 will be zero.
		We can say n is a power of 2 or not based on the value of n&(n-1).
		The expression n&(n-1) will not work when n is 0.
		To handle this case also, our expression will become n& (!n&(n-1))
	*/
public:
	bool isPowerofTwo(long long x) // O(1)
	{
		return x && (!(x & (x - 1)));
		// return __builtin_popcountll(n) == 1; works using the similar logic that i.e checking number of set bits
	}
};

class UsingRightMostBitSet // O(1)
{
public:
	bool isPowerofTwo(long long n)
	{
		if (n == 0)
			return 0;
		if ((n & (~(n - 1))) == n)
			return 1;
		return 0;
	}
};

class SolutionUsingLog2 // O(1)
{
public:
	bool isPowerofTwo(long long n)
	{
		if (n == 0)
			return false;
		return (ceil(log2(n)) == floor(log2(n)));
	}
};

class BruteForce // O(Log2n)
{
public:
	bool isPowerofTwo(long long n)
	{
		if (n == 0)
			return 0;
		while (n != 1)
		{
			if (n % 2 != 0)
				return 0;
			n = n / 2;
		}
		return 1;
	}
};

int main()
{

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		long long n; // input a number n
		cin >> n;

		BruteForce ob;
		if (ob.isPowerofTwo(n)) // Now, if log2 produces an integer not decimal then we are sure raising 2 to this value
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}