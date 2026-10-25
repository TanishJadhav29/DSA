// Problem: Length of Last Word
// Platform: leetcode
// Rating/Difficulty: Easy
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/length-of-last-word/
// Solved on: 2026-10-25T05:38:19.154Z

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        int ans = 0;

        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        while (i >= 0 && s[i] != ' ') {
            ans++;
            i--;
        }

        return ans;
    }
};