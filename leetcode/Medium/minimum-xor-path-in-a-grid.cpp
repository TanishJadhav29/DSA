// Problem: Minimum XOR Path in a Grid
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/minimum-xor-path-in-a-grid/
// Solved on: 2026-10-28T19:08:41.323Z

class Solution {
public:
    int solve(int i,int j,int n,int m,vector<vector<int>>& grid,int num,vector<vector<vector<int>>>&dp){

        if(i==n-1 && j==m-1)return grid[i][j];

        if(dp[i][j][num]!=-1)return dp[i][j][num];
        int curr = num;
        int ans1=INT_MAX;
        int ans2=INT_MAX;
        if(i+1<n)ans1=solve(i+1,j,n,m,grid,num^grid[i][j],dp);
        if(j+1<m)ans2=solve(i,j+1,n,m,grid,num^grid[i][j],dp);
        // cout<<grid[i][j]<<" "<<num<<" "<<ans1<<" "<<ans2<<" "<<(curr^ans1^grid[i][j])<<" "<<(curr^ans2^grid[i][j])<<endl;
        if((curr^ans1^grid[i][j])<(curr^ans2^grid[i][j])){
            // cout<<"return "<<(ans1^grid[i][j])<<endl;
            return dp[i][j][num]=(ans1^grid[i][j]);}
            // cout<<"return "<<(ans2^grid[i][j])<<endl;
            return dp[i][j][num]=(ans2^grid[i][j]);  
    }
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(1024,-1)));
        return solve(0,0,n,m,grid,0,dp);
    }
};