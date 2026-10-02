// Problem: Generate Parentheses
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/generate-parentheses/
// Solved on: 2026-10-02T04:31:53.136Z

class Solution {
public:


void rec(int open,int close,int n,vector<string>&ans,string temp){
    if(open==n){
        string temptemp = temp;
        while(close<n){
            temptemp+=')';
            close++;
        }
        cout<<temptemp<<endl;
        ans.push_back(temptemp);
    }

    if(open<n){
        temp.push_back('(');
        rec(open+1,close,n,ans,temp);
        temp.pop_back();
    }

    if(close<open){
        temp.push_back(')');
        rec(open,close+1,n,ans,temp);
        temp.pop_back();
    }

}
    vector<string> generateParenthesis(int n) {
        string temp="";
        vector<string>ans;
        rec(0,0,n,ans,temp);
        return ans;
    }
};