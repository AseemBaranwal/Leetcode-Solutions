/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Time Complexity : O(N log N)
        // Space Complexity : O(1) if auxiliary space not considered
        vector<vector<int> > mergedIntervals;
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0], end = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            int currStart = intervals[i][0];
            if(currStart <= end) {
                end = max(intervals[i][1], end);
            }else{
                vector<int> temp{start, end};
                mergedIntervals.push_back(temp);
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        vector<int> temp{start, end};
        mergedIntervals.push_back(temp);
        return mergedIntervals;
    }
};
// @lc code=end

/*
Dry Run:
                                i
[[1,3], [2,5], [3, 4], [5,6], [7, 9]]

start : 7
end : 9
mergedIntervals : [[1,6], [7, 9]]

*/