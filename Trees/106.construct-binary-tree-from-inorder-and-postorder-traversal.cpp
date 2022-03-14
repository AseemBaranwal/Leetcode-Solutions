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
    TreeNode *buildTreeUtil(vector<int> &inorder, vector<int> &postorder, int inorderStart, int inorderEnd, int postorderStart, int postEnd){
        if(inorderEnd - inorderStart < 0) return nullptr;
        int leftInorderStartIndex, leftInorderEndIndex, leftPostorderStartIndex, leftPostorderEndIndex, rootPos = inorderStart;
        int rightInorderStartIndex, rightInorderEndIndex, rightPostorderStartIndex, rightPostorderEndIndex;
        // Find the root position
        while(rootPos <= inorderEnd and inorder[rootPos] != postorder[postEnd])
            rootPos++;
        TreeNode *root = new TreeNode(postorder[postEnd]);
        leftInorderStartIndex = inorderStart;
        leftInorderEndIndex = rootPos - 1;
        leftPostorderStartIndex = postorderStart;
        leftPostorderEndIndex = leftPostorderStartIndex + (leftInorderEndIndex - leftInorderStartIndex);
        rightInorderStartIndex = rootPos + 1;
        rightInorderEndIndex = inorderEnd;
        rightPostorderStartIndex = leftPostorderEndIndex + 1;
        rightPostorderEndIndex = postEnd - 1;
        root->left = buildTreeUtil(inorder, postorder, leftInorderStartIndex, leftInorderEndIndex, leftPostorderStartIndex, leftPostorderEndIndex);
        root->right = buildTreeUtil(inorder, postorder, rightInorderStartIndex, rightInorderEndIndex, rightPostorderStartIndex, rightPostorderEndIndex);
        return root;
    }
};
// @lc code=end

