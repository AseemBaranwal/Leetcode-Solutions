/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        // Solution based on the condition that given tree is a perfect trees
        // ie each node has children in pairs
        // Time Complexity : O(N)
        // Space Complexity : O(W) {Width of Tree = N/2}
        if(!root) return NULL;
        Node *left = root->left, *right = root->right, *next = root->next;
        if(left){
            left->next = right;
            if(next)
                right->next = next->left;
            connect(left);
            connect(right);
        }
        return root;
    }
};
// @lc code=end

