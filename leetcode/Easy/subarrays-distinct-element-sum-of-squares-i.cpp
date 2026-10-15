// Problem: Subarrays Distinct Element Sum of Squares I
// Platform: leetcode
// Rating/Difficulty: Easy
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/
// Solved on: 2026-10-15T04:51:13.471Z

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            set<int>s;
            for(int j=i;j<n;j++){
                s.insert(nums[j]);
                ans+=(s.size()*s.size());
                }
            
        }
        return ans;
    }
};