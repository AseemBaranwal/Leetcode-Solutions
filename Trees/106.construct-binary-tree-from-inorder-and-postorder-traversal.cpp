/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return buildTreeUtil(inorder, postorder, 0, n-1, 0, n-1);
    }
private:
    TreeNode *buildTreeUtil(vector<int> &inorder, vector<int> &postorder, int inS, int inE, int postS, int postE){
        if(inE - inS < 0) return nullptr;
        int linS, linE, lpostS, lpostE, rootPos;
        int rinS, rinE, rpostS, rpostE;
        for(int rootPos = inS; rootPos <= inE; rootPos++){
            if(inorder[rootPos] == postorder[postE])
                break;
        }
        TreeNode *root = new TreeNode(postorder[postE]);
        linS = inS;
        linE = rootPos - 1;
        lpostS = postS;
        lpostE = lpostS + (linE - linS);
        rinS = rootPos + 1;
        rinE = inE;
        rpostS = lpostE + 1;
        rpostE = postE - 1;
        root->left = buildTreeUtil(inorder, postorder, linS, linE, lpostS, lpostE);
        root->right = buildTreeUtil(inorder, postorder, rinS, rinE, rpostS, rpostE);
        return root;
    }
};
// @lc code=end

