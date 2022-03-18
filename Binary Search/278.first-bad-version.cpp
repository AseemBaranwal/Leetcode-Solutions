/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int end, int start = 0) {
        // Question based on Binary Search
        // Time Complexity : O(log N)
        if(start > end)
            return INT_MAX;
        int mid = start + (end - start) / 2;
        if(isBadVersion(mid))
            return min(mid, firstBadVersion(mid-1, start));
        else
            return max(mid, firstBadVersion(end, mid+1));
    }
};
// @lc code=end

