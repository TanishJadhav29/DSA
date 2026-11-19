// Problem: Minimum Score by Changing Two Elements
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/minimum-score-by-changing-two-elements/
// Solved on: 2026-11-19T00:49:09.835Z

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int first = nums[0];
        int sec = nums[1];
        int third = nums[2];
        int n = nums.size();
        int firstl = nums[n-1];
        int secl = nums[n-2];
        int thirdl = nums[n-3];

        return min({abs(secl-sec),abs(thirdl-first),abs(firstl-third)});
    }
};