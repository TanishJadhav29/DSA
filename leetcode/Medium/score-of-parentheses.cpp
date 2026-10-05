// Problem: Score of Parentheses
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/score-of-parentheses/
// Solved on: 2026-10-05T12:33:21.202Z

class Solution {
public:
    int solve(string s,map<int,int>&mp,int i){
        if(i>=s.size() || i+1>=s.size())return 0;

        if(s[i]=='(' && s[i+1]==')')return 1+solve(s,mp,i+2);
        if(s[i]=='(' && s[i+1]=='('){
            return 2*solve(s,mp,i+1)+solve(s,mp,mp[i]+1);
        }

        return 0;
    }
    int scoreOfParentheses(string s) {
        map<int,int>mp;
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')st.push(i);
            else {
                mp[st.top()]=i;
                st.pop();
                }
        }

        return solve(s,mp,0);
    }
};