/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        return searchInsertUtil(nums, target, 0, n-1);
    }
private:
    int searchInsertUtil(vector<int> &nums, int &target, int start, int end){
        if(start > end)
            return start;
        int mid = start + (end-start)/2;
        if(nums[mid] < target)
            return searchInsertUtil(nums, target, mid+1, end);
        else
            return searchInsertUtil(nums, target, start, mid-1);
    }
};
// @lc code=end

