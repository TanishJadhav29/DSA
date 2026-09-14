// Problem: 3Sum Closest
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/3sum-closest/
// Solved on: 2026-09-14T20:21:34.385Z

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int i=0;
        int n=nums.size();
        int closest=1e9;
        int ans=-1;
        while(i<n){
            int j=i+1;int k=n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(abs(sum-target)<closest){
                    ans=sum;closest=abs(sum-target);
                }
                if(sum==target)return target;
                if(sum>target)k--;
                if(sum<target)j++;
            }
            i++;
        }
        return ans;
    }
};