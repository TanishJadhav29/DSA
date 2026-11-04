// Problem: Minimum Operations to Make Elements Within K Subarrays Equal
// Platform: leetcode
// Rating/Difficulty: Hard
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/minimum-operations-to-make-elements-within-k-subarrays-equal/
// Solved on: 2026-11-04T13:20:27.350Z

class Solution {
public:
    multiset<int> left, right;
    long long sumLeft = 0, sumRight = 0;
    vector<vector<long long>> dp;

    void balance() {
        while (left.size() > right.size() + 1) {
            int val = *left.rbegin();
            left.erase(left.find(val));
            sumLeft -= val;
            right.insert(val);
            sumRight += val;
        }

        while (left.size() < right.size()) {
            int val = *right.begin();
            right.erase(right.begin());
            sumRight -= val;
            left.insert(val);
            sumLeft += val;
        }
    }

    void insert(int val) {
        if (left.empty() || val <= *left.rbegin()) {
            left.insert(val);
            sumLeft += val;
        } else {
            right.insert(val);
            sumRight += val;
        }
        balance();
    }

    void remove(int val) {
        auto it = left.find(val);

        if (it != left.end()) {
            left.erase(it);
            sumLeft -= val;
        } else {
            it = right.find(val);
            right.erase(it);
            sumRight -= val;
        }
        balance();
    }

    long long getCost() {
        long long median = *left.rbegin();

        return median * left.size() - sumLeft
             + sumRight - median * right.size();
    }

    long long solve(int i, int k, int x, vector<long long>& cost) {
        if (k == 0) return 0;
        if (i >= cost.size()) return 1e18;

        if (dp[i][k] != -1) return dp[i][k];

        long long skip = solve(i + 1, k, x, cost);
        long long take = cost[i] + solve(i + x, k - 1, x, cost);

        return dp[i][k] = min(skip, take);
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        left.clear();
        right.clear();
        sumLeft = sumRight = 0;

        vector<long long> cost(n - x + 1);

        for (int i = 0; i < x; i++) {
            insert(nums[i]);
        }

        cost[0] = getCost();

        for (int i = x; i < n; i++) {
            remove(nums[i - x]);
            insert(nums[i]);
            cost[i - x + 1] = getCost();
        }

        dp.assign(n + 1, vector<long long>(k + 1, -1));

        return solve(0, k, x, cost);
    }
};