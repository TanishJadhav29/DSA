// Problem: Integer Break
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/integer-break/
// Solved on: 2026-11-05T01:11:28.085Z

class Solution {
public:
    
    int solve(int n,vector<int>&dp,int breaked){
        if(dp[n]!=-1)return dp[n];
        int ans;
        if(breaked)ans=n;
        else ans = 1;
        
        for(int i = 1;i<=n/2;i++){
            int first = n-i;
            int sec = i;
            ans=max(max(ans,first*sec),(solve(first,dp,1) * solve(sec,dp,1)));
        }
        cout<<n<<" "<<ans<<endl;
        return dp[n]=ans;
    }
    int integerBreak(int n) {
        int ans=0;
        vector<int>dp(n+1,-1);    
        return solve(n,dp,0);
    }
};