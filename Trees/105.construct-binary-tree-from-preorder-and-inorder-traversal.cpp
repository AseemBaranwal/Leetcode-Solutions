/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Complexity : O(N)
        int n = preorder.size();
        return buildTreeUtil(preorder, 0, n-1, inorder, 0, n-1);
    }
private:
    TreeNode *buildTreeUtil(vector<int> &preorder, int preS, int preE, vector<int> &inorder, int inS, int inE){
        if(preE - preS < 0) return nullptr;
        int leftPreorderStartIndex, leftPreorderEndIndex, leftInorderStartIndex, leftInorderEndIndex, rootPos;
        int rightPreorderStartIndex, rightPreorderEndIndex, rightInorderStartIndex, rightInorderEndIndex;
        for(rootPos = inS; rootPos <= inE; rootPos++){
            if(inorder[rootPos] == preorder[preS])
                break;
        }
        TreeNode *root = new TreeNode(preorder[preS]);
        leftInorderStartIndex = inS;
        leftInorderEndIndex = rootPos - 1;
        leftPreorderStartIndex = preS + 1;
        leftPreorderEndIndex = leftPreorderStartIndex + (leftInorderEndIndex - leftInorderStartIndex);
        rightInorderStartIndex = rootPos + 1;
        rightInorderEndIndex = inE;
        rightPreorderStartIndex = leftPreorderEndIndex + 1;
        rightPreorderEndIndex = preE;
        root->left = buildTreeUtil(preorder, leftPreorderStartIndex, leftPreorderEndIndex, inorder, leftInorderStartIndex, leftInorderEndIndex);
        root->right = buildTreeUtil(preorder, rightPreorderStartIndex, rightPreorderEndIndex, inorder, rightInorderStartIndex, rightInorderEndIndex);
        return root;
    }
};
// @lc code=end

