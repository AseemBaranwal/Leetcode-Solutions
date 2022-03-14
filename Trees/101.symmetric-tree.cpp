/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool isSymmetric(TreeNode* root) {
        // O(N) solution
        if(!root) return true;
        return validate(root->left, root->right);
    }
private:
    bool validate(TreeNode* left, TreeNode* right){
        if(!left and !right) return true;
        if(!left or !right) return false;
        bool firstAnswer = validate(left->right, right->left);
        bool secondAnswer = validate(left->left, right->right);
        return left->val == right->val and firstAnswer and secondAnswer;
    }
};
// @lc code=end

