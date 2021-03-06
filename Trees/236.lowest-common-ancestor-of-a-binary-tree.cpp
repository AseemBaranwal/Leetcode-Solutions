/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Time Complexity : O(N) -- Have to visit all nodes
        if(!root) return NULL;
        TreeNode *leftAnswer = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightAnswer = lowestCommonAncestor(root->right, p, q);
        if(leftAnswer and rightAnswer or root->val == p->val or root->val == q->val)
            return root;
        if(leftAnswer)
            return leftAnswer;
        if(rightAnswer)
            return rightAnswer;
        return NULL;
    }
};
// @lc code=end

