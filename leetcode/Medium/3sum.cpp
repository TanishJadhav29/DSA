// Problem: 3Sum
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/3sum/
// Solved on: 2026-09-14T20:11:33.424Z

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        int n=nums.size();
        vector<vector<int>>ans;
        while(i<n){
            cout<<i<<endl;
            if(i-1>=0){
                while(i<n && nums[i]==nums[i-1])i++;
                cout<<i<<" breaking?"<<endl;
                if(i>=n)break;
            }
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==0){
                    cout<<i<<j<<k<<endl;
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;k--;
                    cout<<j<<k<<endl;
                    while(j<k && nums[j]==nums[j-1])j++;
                    while(j<k && nums[k]==nums[k+1])k--;
                    cout<<j<<k<<endl;
                    if(j>=k)break;
                }
                else if(sum>0)k--;
                else j++;
            }
            i++;
            cout<<i<<j<<k<<endl;
        }
        return ans;
    }
};