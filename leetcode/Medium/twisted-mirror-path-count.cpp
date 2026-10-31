// Problem: Twisted Mirror Path Count
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/twisted-mirror-path-count/
// Solved on: 2026-10-31T19:57:47.498Z

class Solution {
public://1 down
    int mod = 1e9+7;
    int solve(int i,int j,int n,int m,int dir,vector<vector<int>>&grid,vector<vector<int>>&vis,vector<vector<int>>&cnt){
        //cout<<i<<" "<<j<<endl;
        if(i<0 || j<0 || i>=n ||j>=m){
            //cout<<"out"<<endl;
            return 0;
            }
        //cout<<i<<" "<<j<<" "<<grid[i][j]<<" "<<dir<<endl;
        if(i==n-1 && j==m-1){
            //cout<<"at last"<<endl;
            return (cnt[n-1][m-1]%mod);}
        if(vis[i][j]!=0){
            if(grid[i][j]==0){
                ///cout<<"already vis"<<vis[i][j]<<endl;
                return (cnt[i][j]%mod);
            }
            if(grid[i][j]==1 && vis[i][j]%2==dir){
                //cout<<"already vis"<<vis[i][j]<<endl;
                return (cnt[i][j]%mod);
            }
        }
        vis[i][j]=1;
        if(!(i==0 && j==0) && grid[i][j]==1){
            if(dir==1){
                vis[i][j]=3;
                return cnt[i][j]=(solve(i,j+1,n,m,0,grid,vis,cnt)%mod);}
            else {  
                vis[i][j]=2;
                return cnt[i][j]=(solve(i+1,j,n,m,1,grid,vis,cnt)%mod);}
        }
        // cout<<
        cnt[i][j]=(cnt[i][j]+solve(i,j+1,n,m,0,grid,vis,cnt))%mod;
        cnt[i][j]=(cnt[i][j]+solve(i+1,j,n,m,1,grid,vis,cnt))%mod;

        return cnt[i][j];
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>cnt(n,vector<int>(m,0));
        cnt[n-1][m-1]=1;
        return solve(0,0,n,m,-1,grid,vis,cnt);
    }
};