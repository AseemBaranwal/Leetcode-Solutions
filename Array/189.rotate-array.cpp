/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> auxillary(n);
        for(int i = 0; i < n; i++) {
            int newIndex = (i+k)%n;
            auxillary[newIndex] = nums[i];
        }
        for(int i = 0; i < n; i++)
            nums[i] = auxillary[i];
    }
};
// @lc code=end

