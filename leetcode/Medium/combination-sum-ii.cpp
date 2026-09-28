// Problem: Combination Sum II
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/combination-sum-ii/
// Solved on: 2026-09-28T08:25:34.662Z

class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(vector<int>& candidates, int target, int i, vector<int>& temp) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (i == candidates.size() || target < 0)
            return;
        for (int j = i; j < candidates.size(); j++) {
            if (j > i && candidates[j] == candidates[j - 1])
                continue;
            if (candidates[j] > target)
                break;
            temp.push_back(candidates[j]);
            solve(candidates, target - candidates[j], j + 1, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        solve(candidates, target, 0, temp);
        return ans;
    }
};