// Problem: 132 Pattern
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/132-pattern/
// Solved on: 2026-10-14T11:20:57.587Z

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        multiset<int>mst;
        int n = nums.size();
        vector<int> leftMin(n);
        leftMin[0] = nums[0];
        for (int i = 1; i < n; i++) {
            leftMin[i] = min(leftMin[i - 1], nums[i-1]);
            mst.insert(nums[i]);
        }

        for(int i=1;i<n;i++){
            auto it = mst.upper_bound(leftMin[i]);
            auto remove = mst.lower_bound(nums[i]);
            //cout<<leftMin[i]<<" "<<nums[i]<<" "<<endl;
            // for (auto x : mst) {
            //     cout << x << " ";
            // }
            cout<<endl;
            if(it!=mst.end()){
                cout<<(*it)<<endl;
                if(*it<nums[i]){
                    return true;
                    }
            }
            mst.erase(remove);
        }

        return false;
    }
};