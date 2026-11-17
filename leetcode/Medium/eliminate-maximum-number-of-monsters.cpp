// Problem: Eliminate Maximum Number of Monsters
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/eliminate-maximum-number-of-monsters/
// Solved on: 2026-11-17T14:44:13.750Z

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int>time;
        for(int i=0;i<dist.size();i++){
            time.push_back((dist[i] + speed[i] - 1) / speed[i]);
        }
        sort(time.begin(),time.end());
        for(int i=0;i<time.size();i++)cout<<time[i]<<" ";
        int res = 0;
        for(int i=0;i<time.size();i++){
            if(i>=time[i] && !(i==0 && time[i]==0))break;
            res++;
        }
        return res;
    }
};