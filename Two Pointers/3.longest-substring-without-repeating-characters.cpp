/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Two Pointer approach stores 1-based index of element used in a hashmap
        // Time Complexity : O(N)
        // Space Complexity : O(N)
        unordered_map<char, int> lastIndex;
        int start = 0, end = 0, n = s.size(), longestLength = 0;
        while(end < n) {
            if(lastIndex[s[end]] > 0)
                start = max(start, lastIndex[s[end]]);
            longestLength = max(longestLength, end - start + 1);
            lastIndex[s[end]] = end+1;
            end++;
        }
        return longestLength;
    }
};
// @lc code=end
/* Dry Run
abcabcbb
lastIndex{
    a:1,
    b:2,
    c:3
}
longestLength = 3;
start = 0
end = 3
*/