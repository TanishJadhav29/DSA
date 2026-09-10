// Problem: Count Nodes Equal to Average of Subtree
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/
// Solved on: 2026-09-10T04:43:56.121Z

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
pair<int,int> traversal(TreeNode* root,int &cnt){
    if(root==NULL)return {0,0};   
    auto [a,b] = traversal(root->right,cnt);
    auto [c,d] = traversal(root->left,cnt);
    int sum=root->val+a+c;
    
    cout<<root->val<<" "<<sum<<" "<<b+d+1<<" "<<(sum)/(b+d+1)<<endl;
    if((sum)/(b+d+1)==root->val)cnt++;
    return {sum,b+d+1};

}
    int averageOfSubtree(TreeNode* root) {
        int cnt=0;
        int sum=0;
        traversal(root,cnt);
        cout<<cnt;
        return cnt;
    }
};