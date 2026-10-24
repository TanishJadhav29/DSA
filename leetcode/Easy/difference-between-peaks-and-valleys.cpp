// Problem: Difference Between Peaks and Valleys
// Platform: leetcode
// Rating/Difficulty: Easy
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/difference-between-peaks-and-valleys/
// Solved on: 2026-10-24T14:36:57.659Z

class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int peak = 0;
        int valy = 0;
        for(int i=0;i<nums.size();i++){
            if(i>0 && i+1<nums.size()){
                if(nums[i]>nums[i+1] && nums[i]>nums[i-1])peak+=nums[i];
                if(nums[i]<nums[i+1] && nums[i]<nums[i-1])valy+=nums[i];
            }
        }
        return peak-valy;
    }
};