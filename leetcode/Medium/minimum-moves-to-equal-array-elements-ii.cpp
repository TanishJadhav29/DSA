// Problem: Minimum Moves to Equal Array Elements II
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
// Solved on: 2026-11-02T00:03:32.700Z

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()<=1)return 0;

        int n = nums.size();
        int mid = nums[n/2];
        int ans=0;
        for(int i=0;i<n;i++)ans+=abs(mid-nums[i]);
        return ans;
    }
};