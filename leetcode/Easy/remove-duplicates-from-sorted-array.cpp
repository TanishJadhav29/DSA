// Problem: Remove Duplicates from Sorted Array
// Platform: leetcode
// Rating/Difficulty: Easy
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Solved on: 2026-09-19T13:30:05.750Z

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;int j=1;
        int n=nums.size();
        int cnt=1;
        while(j<n){
            while(j<n && nums[j]==nums[j-1])j++;
            if(j>=n)break;
            nums[i+1]=nums[j];
            i++;j++;
            cnt++;
        }
        for(int i=0;i<n;i++)cout<<nums[i]<<" ";
        return cnt;
    }
};