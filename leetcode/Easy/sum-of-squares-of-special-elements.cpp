// Problem: Sum of Squares of Special Elements
// Platform: leetcode
// Rating/Difficulty: Easy
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/sum-of-squares-of-special-elements/
// Solved on: 2026-10-11T05:04:48.868Z

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=(((nums.size()%(i+1))==0)?(nums[i]*nums[i]):0);
            cout<<ans<<endl;
        }  
        return ans; 
    }
};