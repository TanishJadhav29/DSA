// Problem: Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
// Solved on: 2026-11-02T10:10:56.730Z

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int i=0,j=0;
        int ans=0;
        multiset<int>st;

        while(j<nums.size()){
            st.insert(nums[j]);

            while(*st.rbegin()-*st.begin()>limit){
                st.erase(st.find(nums[i]));
                i++;
            }

            ans=max(ans,j-i+1);
            j++;
        }

        return ans;
    }
};