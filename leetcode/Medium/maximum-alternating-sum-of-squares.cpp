// Problem: Maximum Alternating Sum of Squares
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/maximum-alternating-sum-of-squares/
// Solved on: 2026-10-13T05:35:10.242Z

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0)nums[i]*=(-1);
        }

        sort(nums.begin(),nums.end());
        long long add=0;long long sub=0;
        int i=0;int j=nums.size()-1;
        while(i<j){
            add+=(long long)(nums[j]*nums[j]);
            sub+=(long long)(nums[i]*nums[i]);
            i++;j--;
        }
        if(i==j)add+=(long long)(nums[j]*nums[j]);
        return add-sub;
    }
};