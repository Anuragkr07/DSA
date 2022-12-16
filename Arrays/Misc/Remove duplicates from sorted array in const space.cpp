/*

Problem Link:  https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

*/

#include <bits/stdc++.h>
using namespace std;
static auto fast_io = []
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;

        int i = 0, j = 1, c = 1;
        while (j < nums.size())
        {
            if (nums[i] == nums[j])
                j++;
            else
            {
                i++;
                nums[i] = nums[j];
                j++;
                c++;
            }
        }
        return c;
    }
};