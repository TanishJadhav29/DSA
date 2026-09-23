// Problem: Minimum Operations to Reduce X to Zero
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
// Solved on: 2026-09-23T07:15:25.341Z

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0;
        for(int i=0;i<nums.size();i++)sum+=nums[i];
        if(sum<x)return -1;
        if(sum==x)return nums.size();
        int i=0;
        sum=0;
        while(sum<x){
            sum+=nums[i];
            if(sum>=x)break;
            i++;
        }
        int ans = (sum==x?i+1:INT_MAX);
        cout<<ans<<endl;
        int j=nums.size()-1;
        while(j>=0){
            sum+=nums[j--];
            while(sum>x && i>=0)sum-=nums[i--];
            if(sum==x){
                cout<<"0-"<<i<<" "<<j<<"-"<<nums.size()-1<<endl;
                ans=min(ans,i+1+((int)nums.size()-1-j));
                }
            if(sum>x && i<0)break;
        }
        return ans==INT_MAX?-1:ans;
    }
};