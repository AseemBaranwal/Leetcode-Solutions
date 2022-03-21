/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        // Given that only one space is allowed between two words
        // Time Complexity : O(N^2)
        int n = s.size(), wordStart = 0, wordEnd = 0;
        string resString;
        while(wordEnd < n) {
            if(s[wordEnd] == ' ' or wordEnd == n-1) {
                if(wordEnd == n-1) wordEnd++;
                string tmp = s.substr(wordStart, wordEnd-wordStart);
                reverse(tmp.begin(), tmp.end());
                resString += tmp + " ";
                wordStart = wordEnd + 1;
            }
            wordEnd++;
        }
        resString.pop_back();
        return resString;
    }
};
// @lc code=end

