// Problem: Sliding Window Maximum
// Platform: leetcode
// Rating/Difficulty: Hard
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/sliding-window-maximum/
// Solved on: 2026-10-28T19:33:51.428Z

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> st;
        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i < k; i++) {
            st.insert(nums[i]);
        }

        ans.push_back(*st.rbegin());

        for (int i = k; i < n; i++) {
            st.erase(st.find(nums[i - k])); // delete only one occurrence
            st.insert(nums[i]);             // add new element

            ans.push_back(*st.rbegin());    // maximum element
        }

        return ans;
    }
};