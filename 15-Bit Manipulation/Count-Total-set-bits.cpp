/*
	GFG question was not solveable, help needed.
	Problem: Given N, return total number of set bits in every number from 1...N.

	Solution & Explanation :

	* it is very easy to come up with a O(NlogN) solution, for each value count the number of set bits in log2N time.

	* __builtin_popcount  can be used for the same purpose but now C++ 20 has std::__popcount that is preferred and it works in O(Number of bits) complexity.
		__builtin_popcount = int
		__builtin_popcountl = long int
		__builtin_popcountll = long long
	https://en.cppreference.com/w/cpp/numeric/popcount
	https://stackoverflow.com/questions/60165922/stdbitsetncount-vs-builtin-popcount

	Other Optimisations are based on observations : this can be done in O(LogN) and O(N){Leetcode}
	* https://www.geeksforgeeks.org/count-total-set-bits-in-all-numbers-from-1-to-n/
	* https://www.geeksforgeeks.org/count-total-set-bits-in-all-numbers-from-1-to-n-set-2/

Problem Links:
 * https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1
 * https://leetcode.com/problems/counting-bits/
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
}
