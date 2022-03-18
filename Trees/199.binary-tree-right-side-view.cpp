/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    vector<int> rightSideView(TreeNode* root) {
        // Time Complexity : O(N)
        // Space Complexity : O(h) extra recursion Stack space
        vector<int> rightSideViewList;
        rightSideViewUtil(root, rightSideViewList, 1);
        return rightSideViewList;
    }
private:
    void rightSideViewUtil(TreeNode* root, vector<int> &rightSideViewList, int level) {
        if(!root) return;
        if(level > rightSideViewList.size()) 
            rightSideViewList.push_back(root->val);
        rightSideViewUtil(root->right, rightSideViewList, level+1);
        rightSideViewUtil(root->left, rightSideViewList, level+1);
    }
};
// @lc code=end

