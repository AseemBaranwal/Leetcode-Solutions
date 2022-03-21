/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    int kthSmallest(TreeNode* root, int k) {
        // Iterative Solution in O(H(N)) Space and O(N) Time
        stack<TreeNode *> st;
        TreeNode *curr = root;
        while(k > 0 and (!st.empty() or curr)) {
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            if(--k > 0)
                curr = curr->right;
        }
        return curr->val;
    }
};
// @lc code=end

