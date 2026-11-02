// Problem: Word Search
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/word-search/
// Solved on: 2026-11-02T09:57:27.697Z

class Solution {
public:
    bool dfs(int i,int j,int ind,vector<vector<char>>& board,string &word,vector<vector<int>>&vis){
        int n=board.size();
        int m=board[0].size();

        if(ind==word.size())return true;

        if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || board[i][j]!=word[ind]){
            return false;
        }

        vis[i][j]=1;

        bool ans=dfs(i+1,j,ind+1,board,word,vis) ||
                 dfs(i-1,j,ind+1,board,word,vis) ||
                 dfs(i,j+1,ind+1,board,word,vis) ||
                 dfs(i,j-1,ind+1,board,word,vis);

        vis[i][j]=0;

        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(dfs(i,j,0,board,word,vis))return true;
                }
            }
        }

        return false;
    }
};