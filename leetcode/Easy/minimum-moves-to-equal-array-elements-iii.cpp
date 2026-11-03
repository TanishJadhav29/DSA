// Problem: Minimum Moves to Equal Array Elements III
// Platform: leetcode
// Rating/Difficulty: Easy
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/
// Solved on: 2026-11-03T00:42:05.100Z

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());

        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            ans += abs(maxi - nums[i]);
        }

        return ans;
    }
};