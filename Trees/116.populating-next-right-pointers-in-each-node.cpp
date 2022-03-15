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
        // Space Complexity : O(1), Time Complexity : O(N)
        if(!root) return NULL;
        Node *head = root; // head refers to the Parent Node
        while(head){
            Node *childPointer = new Node(-1), *p = childPointer;
            while(head){
                if(head->left){
                    p->next = head->left;
                    p = p->next;
                }
                if(head->right){
                    p->next = head->right;
                    p = p->next;
                }
                head = head->next;
            }
            // Go to next Level
            // After every iteration, the parentNode level is completely linked with next Pointers
            head = childPointer->next;
        }
        return root;
    }
};
// @lc code=end

