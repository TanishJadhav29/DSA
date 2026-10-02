// Problem: Generate Parentheses
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/generate-parentheses/
// Solved on: 2026-10-02T04:23:15.301Z

class Solution {
public:
bool isvalidstring(string temp){
stack<char>st;
for(int i=0;i<temp.size();i++){
if(temp[i]=='('){
    st.push('(');
}
else{
    if(st.size()==0){
        return false;
    }
    st.pop();
}
}
return st.size()==0?true:false;
}

void rec(int open,int close,int n,vector<string>&ans,string temp){
if(open==n&&close==n){
    if(isvalidstring(temp)){ans.push_back(temp);
    }
    return;
}
    if(open<n){
    temp=temp+'(';
    rec(open+1,close,n,ans,temp);
    temp.erase(temp.begin()+(temp.size()-1));
        }
    if(close<n){
    temp=temp+')';
    rec(open,close+1,n,ans,temp);
    temp.erase(temp.begin()+(temp.size()-1));  
        }


}
    vector<string> generateParenthesis(int n) {
        string temp="";
        vector<string>ans;
        rec(0,0,n,ans,temp);
        return ans;
    }
};