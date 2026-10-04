// Problem: Valid Parenthesis String
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/valid-parenthesis-string/
// Solved on: 2026-10-04T17:20:52.509Z

class Solution {
public:
    bool solve(string s,int idx,int oc,int cc,int n,vector<vector<int>>&dp){

        if(idx==n){
            return oc==cc;
        }
        if(oc-cc<0)return false;

        if(dp[idx][oc-cc]!=-1)return dp[idx][oc-cc];

        if(s[idx]=='(')
            return dp[idx][oc-cc]=solve(s,idx+1,oc+1,cc,n,dp);
        if(s[idx]==')')
            return dp[idx][oc-cc]=solve(s,idx+1,oc,cc+1,n,dp);
        if(s[idx]=='*')
            return  dp[idx][oc-cc]=(solve(s,idx+1,oc+1,cc,n,dp) || 
                    solve(s,idx+1,oc,cc+1,n,dp) || 
                    solve(s,idx+1,oc,cc,n,dp));
        return dp[idx][oc-cc]=false;            
    }
    bool checkValidString(string s) {
        vector<vector<int>>dp(s.size()+1,vector<int>(101,-1));
        return solve(s,0,0,0,s.size(),dp);
    }
};