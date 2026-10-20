// Problem: Sum of Sortable Integers
// Platform: leetcode
// Rating/Difficulty: Hard
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/sum-of-sortable-integers/
// Solved on: 2026-10-20T12:51:16.654Z

class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> divisors;

        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                divisors.push_back(i);
            }
        }

        for (int len : divisors) {
            bool valid = true;
            int prevMax = INT_MIN;

            for (int i = 0; i < n; i += len) {
                int mn = INT_MAX;
                int mx = INT_MIN;
                int drops = 0;

                for (int j = i; j < i + len; j++) {
                    mn = min(mn, nums[j]);
                    mx = max(mx, nums[j]);

                    if (j > i && nums[j] < nums[j - 1]) {
                        drops++;
                    }
                }

                if (len > 1 && nums[i] < nums[i + len - 1]) {
                    drops++;
                }

                if (drops > 1) {
                    valid = false;
                    break;
                }

                if (i > 0 && prevMax > mn) {
                    valid = false;
                    break;
                }

                prevMax = mx;
            }

            if (valid) {
                ans += len;
            }
        }

        return ans;
    }
};