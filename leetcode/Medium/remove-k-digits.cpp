// Problem: Remove K Digits
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/remove-k-digits/
// Solved on: 2026-10-14T18:25:27.671Z

class Solution {
public:
    string removeKdigits(string num, int k) {

        stack<char>st;
         
        for(int i=0;i<num.size();i++){
            if(st.empty())st.push(num[i]);
            else{
                while(k && !st.empty() && st.top()-'0'>num[i]-'0'){
                    st.pop();
                    k--;
                    }
                    st.push(num[i]);
            }
        }
        while(k--)st.pop();
        if(st.empty())return "0";
        string ans="";
        while(!st.empty()){
            ans+=st.top();st.pop();
        }
        reverse(ans.begin(),ans.end());
        while(true){
            if(ans.size()>1 && ans[0]=='0')ans.erase(0,1);
            else break;
        }
        return ans;
    }
};