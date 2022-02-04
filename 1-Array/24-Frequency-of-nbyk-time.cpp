/*
    * https://leetcode.com/problems/majority-element/
    * https://leetcode.com/problems/majority-element-ii/
    * https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1#

    Effecient Algorithm Idea:
    * https://gregable.com/2013/10/majority-vote-algorithm-find-majority.html
    * https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm

*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{

    // this is a bit manupuliation solution. for |n/2|
    // not sure if it works.
  public:
    int majorityElement(vector<int> &nums)
    {
        int candidate = 0;
        int n = nums.size();
        for (int i = 0; i < 32; ++i)
        {
            int ones = 0;

            for (int j = 0; j < n; ++j)
                if (nums[j] & 1 << i)
                    ones++;

            if (ones > (n - ones))
                candidate |= 1 << i;
        }

        return candidate;
    }
};

/*

Intution:

If we had some way of counting instances of the majority element as +1+1 and instances of any other element as -1−1,
summing them would make it obvious that the majority element is indeed the majority element.

Algorithm

Essentially, what Boyer-Moore does is look for a suffix sufsuf of nums where suf[0] suf[0] is the majority element in
that suffix. To do this, we maintain a count, which is incremented whenever we see an instance of our current candidate
for majority element and decremented whenever we see anything else. Whenever count equals 0, we effectively forget about
everything in nums up to the current index and consider the current number as the candidate for majority element. It is
not immediately obvious why we can get away with forgetting prefixes of nums - consider the following examples (pipes
are inserted to separate runs of nonzero count).

[7, 7, 5, 7, 5, 1 | 5, 7 | 5, 5, 7, 7 | 7, 7, 7, 7]

Here, the 7 at index 0 is selected to be the first candidate for majority element. count will eventually reach 0 after
index 5 is processed, so the 5 at index 6 will be the next candidate. In this case, 7 is the true majority element, so
by disregarding this prefix, we are ignoring an equal number of majority and minority elements - therefore, 7 will still
be the majority element in the suffix formed by throwing away the first prefix.

[7, 7, 5, 7, 5, 1 | 5, 7 | 5, 5, 7, 7 | 5, 5, 5, 5]

Now, the majority element is 5 (we changed the last run of the array from 7s to 5s), but our first candidate is still 7.
In this case, our candidate is not the true majority element, but we still cannot discard more majority elements than
minority elements (this would imply that count could reach -1 before we reassign candidate, which is obviously false).

Therefore, given that it is impossible (in both cases) to discard more majority elements than minority elements, we are
safe in discarding the prefix and attempting to recursively solve the majority element problem for the suffix.
Eventually, a suffix will be found for which count does not hit 0, and the majority element of that suffix will
necessarily be the same as the majority element of the overall array.

*/

class MooreVotingAlgorithm // O(N) & S(1)
{
  public:
    /* // for n/2
       int majorityElement(vector<int>& nums) {
          int candidate=0,vote=0;
          for(auto &value :nums)
          {
              if(vote==0)
              {
                  candidate=value;
                  vote=1;
              }
              else if(candidate==value)
                  ++vote;
              else
                  --vote;
          }
          return candidate;
      }
    */

    // here question is bit different we have to return multiple values.

    // for majority to be |n/k| the maximum numbers such can be k-1 only.
    // so for 3 we will have 2 values only.
    vector<int> majorityElement(vector<int> &nums)
    {
        int Candidate_1 = INT_MIN, Candidate_2 = INT_MIN, vote1 = 0, vote2 = 0;
        for (auto value : nums)
        {
            if (value == Candidate_1)
                vote1++;
            else if (value == Candidate_2)
                vote2++;
            else if (vote1 == 0)
            {
                Candidate_1 = value;
                vote1++;
            }
            else if (vote2 == 0)
            {
                vote2++;
                Candidate_2 = value;
            }
            else
            {
                vote1--;
                vote2--;
            }
        }

        int freq1 = 0, freq2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == Candidate_1)
                freq1++;
            else if (nums[i] == Candidate_2)
                freq2++;
        }

        vector<int> answer;

        if (freq1 > (nums.size() / 3))
            answer.push_back(Candidate_1);

        if (freq2 > (nums.size() / 3))
            answer.push_back(Candidate_2);

        return answer;
    }
};

class UsingHashMaps // O(N) & S(N)
{
    // Note: Insertion in a Map takes LogN time, we can use unodered_map for and avg of O(1) time hashing, but in case
    // of colliosions we've can have worse case O(n);
  public:
    vector<int> majorityElement(vector<int> &nums)
    {
        vector<int> answer;

        unordered_map<int, int> HashMap;

        int times = nums.size() / 3; // k times

        for (auto &value : nums)
            HashMap[value]++;

        for (auto itr = HashMap.begin(); itr != HashMap.end(); itr++) // itr is an iterator.
            if (itr->second > times)
                answer.emplace_back(itr->first);

        return answer;
    }
};

class NaiveSolution // O(N^2) & S(1)
{
    // for every element we will find it's frequency and if it statisfy's the given |n/k| condition we will add it to
    // our answer

    // NOTE : we have to return the unique elements if we use a vector it will contain multiple values, sio use set, now
    // if we use set then it will take NLOGN time to insert all values. so a better solution is to sort the array.
  public:
    vector<int> majorityElement(vector<int> &nums)
    {
        vector<int> answer;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            count = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[i] == nums[j] && i != j)
                    count++;
            }
            if (count > nums.size() / 3) // or 'k'
                answer.push_back(nums[i]);
        }
        return answer;
    }
};
