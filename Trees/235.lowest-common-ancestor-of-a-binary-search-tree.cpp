/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
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
        // Time Complexity: O(H(N)) since the given Tree is a BST
        // Taking advantage of the sorted order Property
        // Space Complexity: O(H(N))
        if(!root) return NULL;
        if(root->val < p->val and root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        if(root->val > p->val and root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        return root;
    }
};
// @lc code=end

