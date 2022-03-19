/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // O(N) Solution using 2-pointer approach
        int start = 0, end = nums.size() - 1, index = end;
        vector<int> sortedSquaredArray(nums.size());
        while(start <= end){
            if(abs(nums[start]) > abs(nums[end]))
                sortedSquaredArray[index--] = pow(nums[start++], 2);
            else
                sortedSquaredArray[index--] = pow(nums[end--], 2);
        }
        return sortedSquaredArray;
    }
};
// @lc code=end

