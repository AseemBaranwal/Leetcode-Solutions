/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Time Complexity : O(N^2)
        // Space Complexity : O(1)
        // Using Two Pointers and Sorting
        if(nums.size() < 3) return {};
        vector<vector<int> > resSumArray;
        sort(nums.begin(), nums.end());
        int n = nums.size(), i = 0, j = i+1, k = n-1;
        while(i < n-2){
            while(j < k){
                int currSum = nums[i] + nums[j] + nums[k];
                if(currSum > 0)
                    k--;
                else if(currSum < 0)
                    j++;
                else{
                    int left = nums[j], right = nums[k];
                    vector<int>temp{nums[i], nums[j], nums[k]};
                    resSumArray.push_back(temp);
                    while(j < k and nums[j]==left) j++;
                    while(j < k and nums[k]==right) k--;
                }
            }
            int first = nums[i];
            while(first == nums[i] and i < n-2)
                i++;
            j = i + 1;
            k = n-1;
        }
        return resSumArray;
    }
};
// @lc code=end

/*
Intuition
1. Sort the array - O(N log N) {Intro Sort} - {Insertion, Heap, Quick}
2. i, j, k
    i = 0, j = i+1, k = n-1
    while(i < n){
        while(j < k){
        Case 1 : arr[i] + arr[j] + arr[k] > 0
            k--;
        case 2; arr[i] + arr[j] + arr[k] < 0
            j++;
        case 3: arr[i] + arr[j] + arr[k] == 0
            arr.push_back(arr[i],arr[j],arr[k]), k--;
            j++, k--;
        }
        j = i+1, k = n-1
    }

           i   j           k 
           {-3,0,0,0,0,0,3,3,3,3}
Eg. - {-3,-2, -1, 0, 1, 2, 3}
    {-3, 0, 3}, {-3,1,2}

*/