/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> pathToTargetSum;
        vector<int> currPath;
        pathSumUtil(root, targetSum, pathToTargetSum, currPath);
        return pathToTargetSum;
    }
private:
    void pathSumUtil(TreeNode* root, int targetSum, vector<vector<int>> &pathToTargetSum, vector<int>& currPath) {
        if(!root)
            return;
        currPath.push_back(root->val);
        if(!root->left and !root->right and root->val == targetSum)
            pathToTargetSum.push_back(currPath);
        pathSumUtil(root->left, targetSum - root->val, pathToTargetSum, currPath);
        pathSumUtil(root->right, targetSum - root->val, pathToTargetSum, currPath);
        currPath.pop_back();
    }
};
// @lc code=end

