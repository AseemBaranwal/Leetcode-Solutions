/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        // Time Complexity : O(N), Space Complexity : O(1) In Place
        int start = 0, end = s.size()-1;
        while(start < end)
            swap(s[start++], s[end--]);
    }
};
// @lc code=end

