/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
struct BottomSum{
    int continuousSum = 0;
    int maxSum = INT_MIN;
    BottomSum(){}
    BottomSum(int v1, int v2){
        continuousSum = v1;
        maxSum = v2;
    }
};
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        return maxPathSumUtil(root)->maxSum;
    }
private:
    BottomSum *maxPathSumUtil(TreeNode *root){
        if(!root){
            BottomSum *curr = new BottomSum();
            return curr;
        }
        BottomSum *leftAnswer = maxPathSumUtil(root->left);
        BottomSum *rightAnswer = maxPathSumUtil(root->right);
        int subTreesSum = max(leftAnswer->continuousSum, rightAnswer->continuousSum);
        int continuousSum = root->val;
        int maxSum = max(leftAnswer->maxSum, rightAnswer->maxSum);
        continuousSum += subTreesSum > 0 ? subTreesSum : 0;
        int acrossSum = leftAnswer->continuousSum + rightAnswer->continuousSum + root->val;
        maxSum = max(maxSum, max(continuousSum, acrossSum));
        BottomSum *curr = new BottomSum(continuousSum, maxSum);
        return curr;
    }
};
// @lc code=end

