// Problem: Find the Power of K-Size Subarrays II
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/find-the-power-of-k-size-subarrays-ii/
// Solved on: 2026-10-21T18:57:30.231Z

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k==1)return nums;
        
        int cnt=0;
        vector<int>ans;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1)cnt++;
            if(i>=k-1){
                if(cnt==k-1)ans.push_back(nums[i]);
                else ans.push_back(-1);
                if(nums[i-(k-1)]+1==nums[i-(k-1)+1])cnt--;
            }
        }
        return ans;
    }
};