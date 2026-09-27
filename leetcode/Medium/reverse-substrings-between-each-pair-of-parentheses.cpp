// Problem: Reverse Substrings Between Each Pair of Parentheses
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
// Solved on: 2026-09-27T05:33:05.553Z

class Solution {
public:
    string reverseParentheses(string s) {

        string ans="";
        stack<string>st;
        int i=0;
        while(i<s.size()){
            if(s[i]=='('){
                st.push("(");
            }
            else if(s[i]==')'){
                string temp="";
                while(st.top()!="("){
                    string a=st.top();
                    (reverse(a.begin(),a.end()));
                    temp+=a;
                    st.pop();
                }
                st.pop();
                st.push(temp);
            }else{
                string k(1, s[i]);
                st.push(k);
            }
            i++;
        }
        stack<string>v;
        while(!st.empty()){
            v.push(st.top());
            st.pop();
        }
        while(!v.empty()){
            ans+=v.top();
            v.pop();
        }

        return ans;
    }
};