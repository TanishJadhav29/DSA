// Problem: Image Overlap
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/image-overlap/
// Solved on: 2026-09-13T07:49:08.149Z


class Solution {
private:
    int calculateOverlap(const vector<vector<int>>& grid1, const vector<vector<int>>& grid2, int shiftR, int shiftC) {
        int sz = grid1.size();
        int matches = 0;
        
        for (int r = 0; r < sz; ++r) {
            for (int c = 0; c < sz; ++c) {
                int targetR = r + shiftR;
                int targetC = c + shiftC;

                if (targetR < 0 || targetR >= sz || targetC < 0 || targetC >= sz) {
                    continue;
                }

                matches += grid1[r][c] * grid2[targetR][targetC];
            }
        }
        
        return matches;
    }

public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int sz = img1.size();
        int maxMatches = 0;

        for (int shiftR = -(sz - 1); shiftR < sz; ++shiftR) {
            for (int shiftC = -(sz - 1); shiftC < sz; ++shiftC) {
                maxMatches = max(maxMatches, calculateOverlap(img1, img2, shiftR, shiftC));
            }
        }

        return maxMatches;
    }
};

