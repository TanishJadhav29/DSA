// Problem: Find First and Last Position of Element in Sorted Array
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Solved on: 2026-09-20T08:53:52.974Z

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0)return {-1,-1};
        int lb1 = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(lb1>=nums.size() || nums[lb1]!=target)return {-1,-1};
        //reverse(nums.begin(),nums.end());
        int lb2 = (upper_bound(nums.begin(),nums.end(),target)-nums.begin());
        cout<<lb2<<endl;
        if(lb2>=nums.size() || nums[lb2]!=target)lb2--;
        cout<<lb1<<" "<<lb2<<endl;
        return {lb1,lb2};
    }
};