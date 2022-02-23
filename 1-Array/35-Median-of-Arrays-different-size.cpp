#include <bits/stdc++.h>
using namespace std;

/*
    Problem Link :
     * https://leetcode.com/problems/median-of-two-sorted-arrays/

    Solution & Explanation:
    * https://www.youtube.com/watch?v=LPFhl65R7ww

    * https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2481/Share-my-O(log(min(mn)))-solution-with-explanation
 */


class BinarySearch // log(min(N,M)) & S(1)
{
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> nums2)
    {
        int LengthFirst = nums1.size(), LengthSecond = nums2.size();

        if (LengthFirst > LengthSecond)
            return findMedianSortedArrays(nums2, nums1);

        if (LengthFirst + LengthSecond == 1)
            return (double)(nums1.size() > nums2.size()) ? nums1[0] : nums2[0];

        int low = 0, high = LengthFirst;

        while (low <= high)
        {
            int FirstPartitionIndex = (low + high) / 2;

            int SecondPartitionIndex = (LengthFirst + LengthSecond + 1) / 2 - FirstPartitionIndex;
            // i+j (size of left part) = m-i + n-j (size of right part)

            // left side calulations
            int MaxLeftFirst = (FirstPartitionIndex == 0) ? INT_MIN : nums1[FirstPartitionIndex - 1];
            int MaxLeftSecond = (SecondPartitionIndex == 0) ? INT_MIN : nums2[SecondPartitionIndex - 1];

            // right side calulations
            int MinRightFirst = (FirstPartitionIndex == LengthFirst) ? INT_MAX : nums1[FirstPartitionIndex];
            int MinRightSecond = (SecondPartitionIndex == LengthSecond) ? INT_MAX : nums2[SecondPartitionIndex];

            if (MaxLeftFirst <= MinRightSecond and MaxLeftSecond <= MinRightFirst)
            {
                if ((LengthFirst + LengthSecond) & 1)
                    return (double)max(MaxLeftFirst, MaxLeftSecond);

                return ((double)max(MaxLeftFirst, MaxLeftSecond) + min(MinRightFirst, MinRightSecond)) / 2;
            }
            else if (MaxLeftFirst > MinRightSecond)
                high = FirstPartitionIndex - 1;
            else
                low = FirstPartitionIndex + 1;
        }
        return -1;
    }
};

int main()
{

    // consider this case as well
    //[]
    //[1]

    vector<int> nums1 = {3};
    vector<int> nums2 = {-2, -1};

    BinarySearch Ob;
    cout << Ob.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
