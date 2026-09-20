// Problem: Longest Valid Parentheses
// Platform: leetcode
// Rating/Difficulty: Hard
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/longest-valid-parentheses/
// Solved on: 2026-09-20T08:46:04.961Z

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int>v(s.size(),0);
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                int val = -1;
                if(!st.empty()){
                    val=st.top();
                    st.pop();
                }
            if(val!=-1){
                v[val]=1;v[i]=1;
            }
            }
        }
        int len=0;
        int maxlen=0;
        for(int i=0;i<s.size();i++){
            if(v[i]==1){
                len++;
                maxlen=max(maxlen,len);
            }else{
                len=0;
            }
        }
        return maxlen;
    }
};