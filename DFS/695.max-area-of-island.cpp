/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
class Solution {
public:
    vector<vector<int> > vis;
    int m, n;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // DFS Approach to solve the problem
        // Time Complexity: O(M*N)
        int maxSize = 0;
        m = grid.size();
        n = grid[0].size();
        for(int i = 0; i < m; i++){
            vector<int> v(n,0);
            vis.push_back(v);
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j]){
                    int currentSize = findSize(grid, i, j);
                    maxSize = max(currentSize, maxSize);
                }
            }
        }
        return maxSize;
    }
private:
    int findSize(vector<vector<int>> &grid, int r, int c){
        if(r < 0 or r >= m or c < 0 or c >= n or grid[r][c] != 1 or vis[r][c] == 1)
            return 0;
        vis[r][c] = 1;
        int size = 1;
        size += findSize(grid, r+1, c);
        size += findSize(grid, r-1, c);
        size += findSize(grid, r, c+1);
        size += findSize(grid, r, c-1);
        return size;
    }
};
// @lc code=end

