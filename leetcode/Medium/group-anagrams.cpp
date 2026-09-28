// Problem: Group Anagrams
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/group-anagrams/
// Solved on: 2026-09-28T13:23:33.236Z

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        for (string s : strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto it : mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};