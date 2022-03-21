/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
    vector<string> binaryTreePaths(TreeNode* root) {
        // Time Complexity : O(N) using DFS algorithm
        // Space Complexity : O(H(N))
        vector<string> pathVector;
        string currPath;
        binaryTreePathsUtil(root, pathVector, currPath);
        return pathVector;
    }
private:
    void binaryTreePathsUtil(TreeNode *root, vector<string> &pathVector, string &currPath){
        if(!root) return;                       // In case the original root is empty

        if(currPath.empty())                    // Adding the first node to the list
            currPath += to_string(root->val);
        else                                    // Adding the path node along with ->
            currPath += "->" + to_string(root->val);

        if(!root->left and !root->right)
            pathVector.push_back(currPath);
        
        binaryTreePathsUtil(root->left, pathVector, currPath);
        binaryTreePathsUtil(root->right, pathVector, currPath);
    }
};
// @lc code=end

