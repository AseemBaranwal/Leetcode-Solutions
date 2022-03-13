/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool isValidBST(TreeNode* root, long mn = LLONG_MIN, long mx = LLONG_MAX) {
        if(!root) return true;
        bool leftAnswer = isValidBST(root->left, mn, root->val);
        bool rightAnswer = isValidBST(root->right, root->val, mx);
        bool curr = (root->val < mx) && (root->val > mn);
        return leftAnswer && rightAnswer && curr;
    }
};
// @lc code=end

