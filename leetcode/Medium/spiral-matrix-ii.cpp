// Problem: Spiral Matrix II
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/spiral-matrix-ii/
// Solved on: 2026-10-25T05:39:38.014Z


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));

        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int num = 1;

        while (top <= bottom && left <= right) {
            for (int j = left; j <= right; j++)
                ans[top][j] = num++;
            top++;

            for (int i = top; i <= bottom; i++)
                ans[i][right] = num++;
            right--;

            if (top <= bottom) {
                for (int j = right; j >= left; j--)
                    ans[bottom][j] = num++;
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    ans[i][left] = num++;
                left++;
            }
        }

        return ans;
    }
};
