/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        TreeNode *curr = root;
        stack<TreeNode *> st;
        st.push(root);
        stack<TreeNode *> out;
        while(!st.empty()) {
            TreeNode *curr = st.top();
            st.pop();
            out.push(curr);
            if(curr->left){
                st.push(curr->left);
            }
            if(curr->right){
                st.push(curr->right);
            }
        }
        vector<int> postOrderList;
        while(!out.empty()) {
            postOrderList.push_back(out.top()->val);
            out.pop();
        }
        return postOrderList;
    }
};
// @lc code=end

