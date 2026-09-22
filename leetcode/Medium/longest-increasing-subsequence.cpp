// Problem: Longest Increasing Subsequence
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/longest-increasing-subsequence/
// Solved on: 2026-09-22T18:38:57.785Z

class Solution {
public:
    int solve(vector<int>& nums,int i,int prev,int n,vector<vector<int>>&dp){
        if(i>=n)return 0;
        if(dp[i][prev]!=-1)return dp[i][prev];
        int skip = 0+solve(nums,i+1,prev,n,dp);
        int take = INT_MIN;
        if(prev==0 || (nums[prev]<nums[i]))take=1+solve(nums,i+1,i,n,dp);

        return dp[i][prev]=max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        nums.insert(nums.begin(), INT_MIN);
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return solve(nums,1,0,nums.size(),dp);
    }
};