// Problem: Longest Increasing Path in a Matrix
// Platform: leetcode
// Rating/Difficulty: Hard
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
// Solved on: 2026-11-02T14:53:09.341Z

class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& matrix,
              vector<vector<int>>& ans, int n, int m) {

        if (ans[i][j] != 0) return ans[i][j];

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        int maxi = 1;

        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];

            if (x >= 0 && y >= 0 && x < n && y < m &&
                matrix[x][y] > matrix[i][j]) {

                maxi = max(maxi, 1 + solve(x, y, matrix, ans, n, m));
            }
        }

        return ans[i][j] = maxi;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> ans(n, vector<int>(m, 0));

        int res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                res = max(res, solve(i, j, matrix, ans, n, m));

            }
        }

        return res;
    }
};