/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // Complexity: O(N)
        if(!root) return {};
        queue<TreeNode *> Q; Q.push(root);
        vector<vector<int>> zigzagLevelOrderSequence;
        bool leftToRight = true;
        while(!Q.empty()){
            int levelSize = Q.size();
            vector<int> level(levelSize);
            for(int i = 0; i < levelSize; i++){
                TreeNode *curr = Q.front(); Q.pop();
                if(leftToRight)
                    level[i] = curr->val;
                else
                    level[levelSize-i-1] = curr->val;
                if(curr->left)
                    Q.push(curr->left);
                if(curr->right)
                    Q.push(curr->right);
            }
            leftToRight = !leftToRight;
            zigzagLevelOrderSequence.push_back(level);
        }
        return zigzagLevelOrderSequence;
    }
};
// @lc code=end

