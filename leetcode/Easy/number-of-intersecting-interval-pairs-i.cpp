// Problem: Number of Intersecting Interval Pairs I
// Platform: leetcode
// Rating/Difficulty: Easy
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/number-of-intersecting-interval-pairs-i/
// Solved on: 2026-09-20T19:39:09.263Z

class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int cnt=0;
        for(int i=0;i<intervals.size();i++){
            for(int j=i+1;j<intervals.size();j++){
                if(
                (intervals[i][0]>=intervals[j][0] && 
                intervals[j][1]>=intervals[i][0]) || 
                (intervals[j][0]>=intervals[i][0] && 
                intervals[i][1]>=intervals[j][0])){
                    cnt++;
                    }
            }
        }
        return cnt;
    }
};