// Problem: Rotate Image
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/rotate-image/
// Solved on: 2026-09-28T13:15:52.063Z

class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat.size();j++){
                if(i==j)break;
                swap(mat[i][j],mat[j][i]);
            }
        }

        for(int i=0;i<mat.size();i++)
            reverse(mat[i].begin(), mat[i].end());        

        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat.size();j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
};