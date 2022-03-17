/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
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
class BSTIterator {
public:
    // Time Complexity of all Functions except constructor : O(N)
    // Space Complexity : O(N)
    BSTIterator(TreeNode* root) {
        TreeNode *curr = root;
        stack<TreeNode *> st;
        while(!st.empty() or curr) {
            while(curr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            nodeList.push_back(curr->val);
            curr = curr->right;
        }
    }
    
    int next() {
        return nodeList[index++];
    }
    
    bool hasNext() {
        return index < nodeList.size();
    }
private:
    vector<int> nodeList;
    int index = 0;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

