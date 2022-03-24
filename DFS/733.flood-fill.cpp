/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // DFS Approach Time Complexity : O(N*M)
        // Space Complexity : O(1) if call stack isn't taken into account
        if(image[sr][sc] == newColor) return image;
        fillColor(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
private:
    void fillColor(vector<vector<int>> &image, int sr, int sc, int color, int newColor) {
        if(sr < 0 or sr >= image.size() or sc < 0 or sc >= image[0].size() or image[sr][sc] != color)
            return;
        image[sr][sc] = newColor;
        fillColor(image, sr + 1, sc, color, newColor);
        fillColor(image, sr, sc + 1, color, newColor);
        fillColor(image, sr - 1, sc, color, newColor);
        fillColor(image, sr, sc - 1, color, newColor);
    }
};
// @lc code=end

