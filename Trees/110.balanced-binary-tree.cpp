/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    bool isBalanced(TreeNode* root) {
        // O(N) Solution
        return isBalancedUtil(root).second;
    }
private:
    pair<int, bool> isBalancedUtil(TreeNode* root){
        if(!root) return {0, true};
        pair<int, bool> leftAnswer = isBalancedUtil(root->left);
        pair<int, bool> rightAnswer = isBalancedUtil(root->right);
        int height = 1 + max(leftAnswer.first, rightAnswer.first);
        bool balanced = abs(leftAnswer.first - rightAnswer.first) <= 1 && leftAnswer.second && rightAnswer.second;
        return {height, balanced};
    }
};
// @lc code=end

