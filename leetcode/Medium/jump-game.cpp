// Problem: Jump Game
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/jump-game/
// Solved on: 2026-10-25T05:33:11.148Z

class Solution {
public:
    bool canJump(vector<int>& nums) {
       int maxi=0;
       for(int i=0;i<nums.size();i++){
            if(maxi>=i)maxi=max(maxi,i+nums[i]);
            else return false;
       } 
       return true;
    }
};