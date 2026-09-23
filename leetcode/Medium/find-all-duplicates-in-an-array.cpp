// Problem: Find All Duplicates in an Array
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/find-all-duplicates-in-an-array/
// Solved on: 2026-09-23T20:51:28.956Z

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
      sort(nums.begin(),nums.end());
      int j=0;
      for(int i=0;i<nums.size()-1;i++){
        if(nums[i]==nums[i+1]){
            ans.push_back(nums[i]);
           while(i<nums.size()-1&&nums[i]==nums[i+1]){
            i++;
           }

        }
        
      }
      return ans;

        
    }
};