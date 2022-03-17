/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
    int sumNumbers(TreeNode* root, int currSum=0) {
        // Time Complexity: O(N)
        // Top-down Approach
        if(!root) return 0;
        int sumToNode = currSum*10 + root->val;
        if(!root->left and !root->right){
            sum += sumToNode;
            return sum;
        }
        sumNumbers(root->left, sumToNode);
        sumNumbers(root->right, sumToNode);
        return sum;
    }
private:
    int sum = 0;
};
// @lc code=end

