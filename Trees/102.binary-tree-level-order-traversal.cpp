/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // Time Complexity : O(N)
        if(!root) return {};
        vector<vector<int>> levelOrderTraversal;
        queue<TreeNode *>Q; Q.push(root);
        while(!Q.empty()) {
            int levelSize = Q.size();
            vector<int> currLevel;
            for(int i = 0; i < levelSize; i++){
                TreeNode *curr = Q.front(); Q.pop();
                currLevel.push_back(curr->val);
                if(curr->left)
                    Q.push(curr->left);
                if(curr->right)
                    Q.push(curr->right);
            }
            levelOrderTraversal.push_back(currLevel);
        }
        return levelOrderTraversal;
    }
};
// @lc code=end

