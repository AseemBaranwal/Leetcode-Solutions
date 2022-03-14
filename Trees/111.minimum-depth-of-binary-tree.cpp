/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    int minDepth(TreeNode* root) {
        // Level Order Traversal - O(N)
        if(!root) return 0;
        queue<TreeNode *>Q; Q.push(root);
        int minimumDepth = 1;
        while(!Q.empty()) {
            int levelSize = Q.size();
            for(int i = 0; i < levelSize; i++){
                TreeNode *currNode = Q.front();
                Q.pop();
                if(currNode->left)
                    Q.push(currNode->left);
                if(currNode->right)
                    Q.push(currNode->right);
                if(!currNode->left and !currNode->right)
                    return minimumDepth;
            }
            minimumDepth++;
        }
        return minimumDepth;
    }
};
// @lc code=end

