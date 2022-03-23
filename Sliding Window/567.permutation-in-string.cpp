/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Time Complexity : O(26*N) = O(N)
        // Space Complexity : O(26) = O(1)
        int countValues[26];
        memset(countValues, 0, sizeof(countValues));
        int s1Size = s1.size(), s2Size = s2.size();
        if(s1Size > s2Size) return false; 
        // Permuatation not possible as no sufficient characters
        int currentIndex = 0;
        while(currentIndex < s1Size){
            countValues[s1[currentIndex] - 'a']++;
            countValues[s2[currentIndex] - 'a']--;
            currentIndex++;
        }
        // Check if both strings are permutation of each other
        if(checkSubstring(countValues)) return true;
        while(currentIndex < s2Size) {
            countValues[s2[currentIndex-s1Size] - 'a']++;
            countValues[s2[currentIndex] - 'a']--;
            // Check if string[i ... s1size+i] is a permutation of s1
            if(checkSubstring(countValues)) return true;
            currentIndex++;
        }
        // Couldn't find
        return false;
    }
private:
    bool checkSubstring(int countValues[]){
        for(int i = 0; i < 26; i++)
            if(countValues[i])
                return false;
        return true;
    }
};
// @lc code=end

