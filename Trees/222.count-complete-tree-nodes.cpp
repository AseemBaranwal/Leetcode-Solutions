/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
    int countNodes(TreeNode* root) {
        // Time Complexity Usual : O(N2)
        // In this question, since this is a binary tree, time complexity of height = O(logN), hence total time complexity = O((log N)2)
        if(!root) return 0;
        int currHeight = height(root), nodeCount = 0;
        while(root){
            if(height(root->right) == currHeight-1){
                nodeCount += 1<<currHeight;
                root = root->right;
            }else{
                nodeCount += 1<<currHeight-1;
                root = root->left;
            }
            currHeight--;
        }
        return nodeCount;
    }
private:
    int height(TreeNode* root){
        return root ? 1 + height(root->left) : -1;
    }
};
// @lc code=end

