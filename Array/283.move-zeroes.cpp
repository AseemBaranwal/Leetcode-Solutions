/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // O(1) Space and O(N) Time
        int numZeros = 0, n = nums.size(), i = -1;
        while(++i < n) {
            if(nums[i] == 0)
                numZeros++;
            else
                nums[i-numZeros] = nums[i];
        }
        i = n-numZeros-1;
        while(++i < nums.size())
            nums[i] = 0;
    }
};
// @lc code=end

