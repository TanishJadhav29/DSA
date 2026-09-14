// Problem: 4Sum
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/4sum/
// Solved on: 2026-09-14T20:26:34.241Z

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        int i = 0;
        int n = nums.size();

        vector<vector<int>> ans;

        while (i < n) {

            if (i > 0) {
                while (i < n && nums[i] == nums[i - 1])
                    i++;

                if (i >= n)
                    break;
            }

            int j = i + 1;

            while (j < n) {

                if (j > i + 1) {
                    while (j < n && nums[j] == nums[j - 1])
                        j++;

                    if (j >= n)
                        break;
                }

                int k = j + 1;
                int l = n - 1;

                while (k < l) {

                    long long sum = (long long)nums[i]
                                  + nums[j]
                                  + nums[k]
                                  + nums[l];

                    if (sum == target) {

                        ans.push_back({
                            nums[i],
                            nums[j],
                            nums[k],
                            nums[l]
                        });

                        k++;
                        l--;

                        while (k < l && nums[k] == nums[k - 1])
                            k++;

                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    }

                    else if (sum > target) {
                        l--;
                    }

                    else {
                        k++;
                    }
                }

                j++;
            }

            i++;
        }

        return ans;
    }
};