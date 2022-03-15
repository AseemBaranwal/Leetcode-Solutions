/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
struct LLNode{
    TreeNode *head = NULL;
    TreeNode *tail = NULL;
};

class Solution {
public:
    void flatten(TreeNode* root) {
        // Time Complexity : O(N)
        // Space Complexity : O(1)
        flattenTree(root);
    }
private:
    LLNode flattenTree(TreeNode* root){
        if(!root) 
            return {nullptr, nullptr};
        LLNode leftAnswer = flattenTree(root->left);
        LLNode rightAnswer = flattenTree(root->right);
        root->left = NULL;
        TreeNode *currHead = root, *currTail = root;
        if(leftAnswer.tail){
            root->right = leftAnswer.head;
            leftAnswer.tail->right = rightAnswer.head;
            currTail = leftAnswer.tail;
        }
        if(rightAnswer.tail)
            currTail = rightAnswer.tail;
        return {currHead, currTail};
    }
};
// @lc code=end

