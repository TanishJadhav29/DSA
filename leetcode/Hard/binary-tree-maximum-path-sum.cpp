// Problem: Binary Tree Maximum Path Sum
// Platform: leetcode
// Rating/Difficulty: Hard
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Solved on: 2026-10-13T14:19:38.828Z

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root,int& maxi){
        if(root==NULL)return 0;
        int right = solve(root->right,maxi);
        int left = solve(root->left,maxi);
        maxi = max({maxi,
                    root->val,
                    root->val+left,
                    root->val+left+right,
                    root->val+right});
        return max({root->val,
                    root->val+left,
                    root->val+right});
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        solve(root,maxi);
        return maxi;
    }
};