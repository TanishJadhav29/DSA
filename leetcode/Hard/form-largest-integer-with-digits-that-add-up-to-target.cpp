// Problem: Form Largest Integer With Digits That Add up to Target
// Platform: leetcode
// Rating/Difficulty: Hard
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target/
// Solved on: 2026-11-19T16:27:17.242Z


class Solution {
public:
    vector<vector<string>> dp;

    string solve(int i, int n, vector<int>& cost, int target) {
        if (target == 0) return "";

        if (i == n - 1) {
            if (target % cost[i] == 0) {
                string k(target / cost[i], '0' + (i + 1));
                return k;
            }
            return "#";
        }

        if (dp[i][target] != "?") return dp[i][target];

        string ans1 = solve(i + 1, n, cost, target);
        string ans2 = "#";

        if (cost[i] <= target) {
            int k = i + 1;
            string a = to_string(k);

            string temp = solve(i, n, cost, target - cost[i]);

            if (temp != "#") {
                ans2 = temp + a;
            }
        }

        if (ans1 == "#") return dp[i][target] = ans2;
        if (ans2 == "#") return dp[i][target] = ans1;

        if (ans1.size() > ans2.size())
            return dp[i][target] = ans1;

        if (ans2.size() > ans1.size())
            return dp[i][target] = ans2;

        return dp[i][target] = max(ans1, ans2);
    }

    string largestNumber(vector<int>& cost, int target) {
        int n = cost.size();

        dp.assign(n, vector<string>(target + 1, "?"));

        string ans = solve(0, n, cost, target);

        return ans == "#" ? "0" : ans;
    }
};
