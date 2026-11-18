// Problem: Minimum Number of Changes to Make Binary String Beautiful
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/
// Solved on: 2026-11-18T06:15:46.778Z

class Solution {
public:
    int minChanges(string s) {
        int ans = 0;
        for(int i=0;i<s.size();i+=2){
            if(i+1<s.size() && s[i]!=s[i+1])ans++;
        }
        return ans;
    }
};