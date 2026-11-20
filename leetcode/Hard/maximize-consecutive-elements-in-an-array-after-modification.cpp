// Problem: Maximize Consecutive Elements in an Array After Modification
// Platform: leetcode
// Rating/Difficulty: Hard
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/maximize-consecutive-elements-in-an-array-after-modification/
// Solved on: 2026-11-20T05:47:26.161Z

class Solution {
public:
    int solve(vector<int>& nums,int i,int add,int n,bool ntk,       vector<vector<vector<int>>>&dp){
        if(i>=n)return 0;

        if(dp[i][add][ntk]!=-1)return dp[i][add][ntk];

        if(ntk){
            int nt=solve(nums,i+1,add,n,ntk,dp);

            int cur = nums[i]+add;
            int sidx = lower_bound(i+1+nums.begin(),nums.end(),cur) - nums.begin();
            int didx = lower_bound(i+1+nums.begin(),nums.end(),cur+1) - nums.begin();
            int s = (sidx<n && nums[sidx]==cur?solve(nums,sidx,1,n,false,dp):0);
            int d = (didx<n && nums[didx]==cur+1?solve(nums,didx,0,n,false,dp):0);
            int tk1 = 1+max(s,d);
            //dp[i][0][ntk]=tk1;

            // cur = nums[i]+1;
            // sidx = lower_bound(i+1+nums.begin(),nums.end(),cur) - nums.begin();
            // didx = lower_bound(i+1+nums.begin(),nums.end(),cur+1) - nums.begin();
            // s = (sidx<n && nums[sidx]==cur?solve(nums,sidx,1,n,false,dp):0);
            // d = (didx<n && nums[didx]==cur+1?solve(nums,didx,0,n,false,dp):0);
            // int tk2 = 1+max(s,d);
            //dp[i][1][ntk]=tk2;

            return dp[i][add][ntk]=max(nt,tk1);
        }else{
            int cur = nums[i]+add;
            int sidx = lower_bound(i+1+nums.begin(),nums.end(),cur) - nums.begin();
            int didx = lower_bound(i+1+nums.begin(),nums.end(),cur+1) - nums.begin();
            int s = (sidx<n && nums[sidx]==cur?solve(nums,sidx,1,n,false,dp):0);
            int d = (didx<n && nums[didx]==cur+1?solve(nums,didx,0,n,false,dp):0);
            int tk1 = 1+max(s,d);
            return dp[i][add][ntk]=tk1;
        }
    }
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        //for(int i=0;i<nums.size();i++)cout<<nums[i]<<" ";
        vector<vector<vector<int>>> dp(nums.size()+1, vector<vector<int>>(2, vector<int>(2, -1)));
        //cout<<endl;
        return max(solve(nums,0,0,nums.size(),true,dp),
        solve(nums,0,1,nums.size(),true,dp));
    }
};