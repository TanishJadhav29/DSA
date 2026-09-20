// Problem: Number of Intersecting Interval Pairs II
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/number-of-intersecting-interval-pairs-ii/
// Solved on: 2026-09-20T19:46:51.847Z

class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        long long cnt=0;
        for(int i=0;i<intervals.size();i++){
            int s=i+1;int h=intervals.size()-1;
            while(s<=h && s<intervals.size() && h>=0){
                int mid = (s+h)/2;
                int start = intervals[mid][0];
                int end = intervals[mid][1];
                if(start<=intervals[i][1]){
                    s=mid+1;
                }else{
                    h=mid-1;
                }
            }
            cnt+=(h-i);
        }
        return cnt;
    }
};