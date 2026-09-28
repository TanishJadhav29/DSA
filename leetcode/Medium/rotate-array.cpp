// Problem: Rotate Array
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/rotate-array/
// Solved on: 2026-09-28T21:58:10.035Z

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k=k%n;
        if(k==0)return ;
        vector<int>lastk;
        for(int i=n-1;i>n-k-1;i--){
            lastk.push_back(nums[i]);
        }
        cout<<"yes\n";
        for(int i=n-1;i>=k;i--){
            nums[i]=nums[i-k];
        }
        cout<<"yes\n";
        reverse(lastk.begin(),lastk.end());
        cout<<lastk.size();
        for(int i=0;i<k;i++){
            nums[i]=lastk[i];
        }
        cout<<"yes\n";
        return ;
    }
};