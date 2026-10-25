// Problem: Number of Closed Islands
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/number-of-closed-islands/
// Solved on: 2026-10-25T03:52:27.605Z

class Solution {
public:
    int row[4]={0,0,1,-1};
    int col[4]={1,-1,0,0};

    bool check(int i,int j,int n,int m){
        return (i>=0 && j>=0 && i<n && j<m);
    }
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&vis,vector<vector<int>>&boolean,int n,int m){
        if(i==0 || j==0 || i==n-1 || j==m-1)return false;

        if(vis[i][j]==1 && boolean[i][j]!=0)return boolean[i][j];

        vis[i][j]=1;
        int closed = 2;
        for(int k=0;k<4;k++){
            int newi = i+row[k];
            int newj = j+col[k];
            if(check(newi,newj,n,m)){
                if(grid[newi][newj]==0 &&
                    vis[newi][newj]==1 &&
                    boolean[newi][newj]!=0)closed=min(closed,boolean[newi][newj]);

                else if(grid[newi][newj]==0 &&
                        vis[newi][newj]==0)
                    closed=min(closed,solve(newi,newj,grid,vis,boolean,n,m));      
            }
        }
        return boolean[i][j]=closed;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
       vector<vector<int>>vis(n,vector<int>(m,0));
       vector<vector<int>>boolean(n,vector<int>(m,0)); 
        int ans=0;
       for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 && vis[i][j]==0){
                    int k = ((solve(i,j,grid,vis,boolean,n,m)==2)?1:0);
                    ans+=k;
                    cout<<i<<" "<<j<<" "<<k<<endl;
                }
                //else if(grid[i][j]==0)cout<<i<<" "<<j<<"done"<<endl;
            }
       }
       return ans;
    }
};