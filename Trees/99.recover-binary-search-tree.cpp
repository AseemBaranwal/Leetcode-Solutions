/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
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
    void recoverTree(TreeNode* root) {
        // Time Complexity : O(N)
        // Space Complexity: O(1) if we ignore the recursion stack
        inorder(root);
        if(first and last)
            swap(first->val, last->val);
        else
            swap(first->val, mid->val);
    }
private:
    TreeNode *prev = NULL;
    TreeNode *first = NULL;
    TreeNode *last = NULL;
    TreeNode *mid = NULL;
    void inorder(TreeNode *node) {
        if(!node) return;
        inorder(node->left);
        if(prev and prev->val > node->val){
            if(first)
                last = node;
            else{
                mid = node;
                first = prev;
            }
        }
        prev = node;
        inorder(node->right);
    }
};
// @lc code=end

