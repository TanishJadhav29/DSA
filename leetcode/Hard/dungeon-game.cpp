// Problem: Dungeon Game
// Platform: leetcode
// Rating/Difficulty: Hard
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/dungeon-game/
// Solved on: 2026-10-14T03:14:10.751Z

class Solution {
public:
    int solve(vector<vector<int>>& dungeon,int i,int j,int n,int m,vector<vector<int>>&dp){

            if(i==n-1 && j==m-1){
                return dp[i][j]=dungeon[i][j]<=0?dungeon[i][j]:0;
            }
            if(dp[i][j]!=1)return dp[i][j];
            int right=INT_MIN;
            int down =INT_MIN;
            if(i+1<n)down = solve(dungeon,i+1,j,n,m,dp);
            if(j+1<m)right= solve(dungeon,i,j+1,n,m,dp);
            //cout<<i<<" "<<j<<" "<<max(right,down)<<" "<<dungeon[i][j]+max(right,down)<<endl;
            if(dungeon[i][j]+max(right,down)>0)return dp[i][j]=0;
            return dp[i][j]=dungeon[i][j]+max(right,down);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<vector<int>>dp(dungeon.size()+1,vector<int>(dungeon[0].size()+1,1));
       int ans=solve(dungeon,0,0,dungeon.size(),dungeon[0].size(),dp);
       return abs(ans)+1;
    }
};