// Problem: Combinations
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/combinations/
// Solved on: 2026-11-02T09:58:45.983Z

class Solution {
public:
    void solve(int i,int n,int k,vector<int>&temp,vector<vector<int>>&ans){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }

        for(int j=i;j<=n;j++){
            temp.push_back(j);
            solve(j+1,n,k,temp,ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;

        solve(1,n,k,temp,ans);

        return ans;
    }
};