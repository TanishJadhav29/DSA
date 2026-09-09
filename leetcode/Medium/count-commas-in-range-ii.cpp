// Problem: Count Commas in Range II
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/count-commas-in-range-ii/
// Solved on: 2026-09-09T14:54:49.474Z

class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long a = 999;
        long long i = 1;

        while (a < n) {
            long long next = a * 1000 + 999;

            if (next > n) {
                ans += (n - a) * i;
                break;
            }

            ans += (next - a) * i;
            a = next;
            i++;
        }

        return ans;
    }
};