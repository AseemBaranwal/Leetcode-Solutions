/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return nullptr;
        return createBST(nums, 0, nums.size() - 1);
    }
private:
    TreeNode *createBST(vector<int>& nums, int start, int end) {
        if(end < start)
            return NULL;
        int mid = start + (end - start)/2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = createBST(nums, start, mid-1);
        node->right = createBST(nums, mid+1, end);
        return node;
    }
};
// @lc code=end

