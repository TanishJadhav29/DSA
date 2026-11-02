// Problem: Frog Jump
// Platform: leetcode
// Rating/Difficulty: Hard
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/frog-jump/
// Solved on: 2026-11-02T16:01:54.382Z

class Solution {
public:
    int dp[2001][2001];

    bool solve(int ind, int k, vector<int>& stones, int n) {

        if (ind == n - 1) return true;

        if (dp[ind][k] != -1) return dp[ind][k];

        for (int i = ind + 1; i < n; i++) {

            int jump = stones[i] - stones[ind];

            if (jump == k - 1 || jump == k || jump == k + 1) {

                if (solve(i, jump, stones, n)) {
                    return dp[ind][k] = true;
                }
            }
        }

        return dp[ind][k] = false;
    }

    bool canCross(vector<int>& stones) {

        int n = stones.size();

        if (n == 1) return true;
        if (stones[1] != 1) return false;

        memset(dp, -1, sizeof(dp));

        return solve(1, 1, stones, n);
    }
};