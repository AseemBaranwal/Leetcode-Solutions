/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // O(N) Time using Two pointers
        vector<int> resIndex(2);
        int start = 0, end = numbers.size() - 1;
        while(start < end){
            int currSum = numbers[start] + numbers[end];
            if(currSum < target)
                start++;
            else if(currSum > target)
                end--;
            else{
                resIndex[0] = start+1;
                resIndex[1] = end+1;
                break;
            }
        }
        return resIndex;
    }
};
// @lc code=end

