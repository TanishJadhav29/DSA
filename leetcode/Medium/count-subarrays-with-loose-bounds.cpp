// Problem: Count Subarrays With Loose Bounds
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/count-subarrays-with-loose-bounds/
// Solved on: 2026-10-24T14:40:33.837Z

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        long long a=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=minK && nums[i]<=maxK){
                ans+=a;
                a++;
            }else a=1;
        }
        return ans;
    }
};