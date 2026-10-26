// Problem: Count Islands With Total Value Divisible by K
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/
// Solved on: 2026-10-26T06:10:18.414Z

class Solution {
public:
    int row[4]={0,0,1,-1};
    int col[4]={1,-1,0,0};
    bool check(int i,int j,int n,int m){
        return (i>=0 && j>=0 && i<n && j<m);
    }
    long long solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis,int n,int m){

        vis[i][j]=1;
        long long ans=grid[i][j];
        for(int k=0;k<4;k++){
            int newi=i+row[k];
            int newj=j+col[k];
            if(check(newi,newj,n,m) && !vis[newi][newj] && grid[newi][newj]!=0){
               // cout<<"recursive call"<<newi<<" "<<newj<<endl;
                ans+=solve(newi,newj,grid,vis,n,m);
                }
        }
        return ans;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]!=0){
                    long long v=solve(i,j,grid,vis,n,m);
                    //cout<<v<<endl;
                    cnt+=(v%k==0?1:0);
                }
            }
        }
        return cnt;
    }
};