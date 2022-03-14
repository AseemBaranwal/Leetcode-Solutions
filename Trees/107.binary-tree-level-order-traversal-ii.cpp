/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        int depthOfTree = depth(root);
        vector<vector<int>> levelOrderReverse(depthOfTree);
        nodeAtLevelK(levelOrderReverse, depthOfTree, root, 0);
        return levelOrderReverse;
    }
private:
    int depth(TreeNode* root){
        if(!root) return 0;
        return 1 + max(depth(root->left), depth(root->right));
    }
    void nodeAtLevelK(vector<vector<int>> &levelOrderReverse, int &depth, TreeNode *root, int currentLevel) {
        if(!root) return;
        levelOrderReverse[depth-currentLevel-1].push_back(root->val);
        nodeAtLevelK(levelOrderReverse, depth, root->left, currentLevel+1);
        nodeAtLevelK(levelOrderReverse, depth, root->right, currentLevel+1);
    }
};
// @lc code=end

