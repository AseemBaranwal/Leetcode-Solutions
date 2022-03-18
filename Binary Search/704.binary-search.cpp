/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Time Complexity : O(N)
        return binarySearch(nums, target, 0, nums.size()-1);
    }
private:
    int binarySearch(vector<int>& nums, int &target, int start, int end){
        if(start > end)
            return -1;
        int mid = start + (end-start)/2;
        if(nums[mid] < target)
            return binarySearch(nums, target, mid+1, end);
        else if(nums[mid] > target)
            return binarySearch(nums, target, start, mid-1);
        else
            return mid;
    }
};
// @lc code=end

