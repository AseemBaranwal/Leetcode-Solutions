/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Using an extra dummy node to prevent writing separate conditions
        ListNode *dummy = new ListNode(-1, head);
        ListNode *ahead = head, *behind = dummy;
        for(int i = 0; i < n; i++) ahead = ahead->next;
        while(ahead) {
            behind = behind->next;
            ahead = ahead->next;
        }
        ListNode *toBeDeleted = behind->next;
        behind->next = behind->next->next;
        delete toBeDeleted;
        return dummy->next;
    }
};
// @lc code=end

