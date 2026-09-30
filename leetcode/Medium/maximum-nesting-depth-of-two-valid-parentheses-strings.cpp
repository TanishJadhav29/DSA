// Problem: Maximum Nesting Depth of Two Valid Parentheses Strings
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/
// Solved on: 2026-09-30T05:08:46.718Z

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        stack<pair<int,int>>st;
        int n=seq.size();
        vector<int>result(n,0);
        for(int i=0;i<n;i++){
            if(seq[i]=='('){
                if(!st.empty()){
                    pair<int,int>temp = st.top();
                    st.push({!temp.first,i});
                }else st.push({0,i});
            }else{
                pair<int,int>temp = st.top();
                st.pop();
                result[i]=temp.first;
                result[temp.second]=temp.first;
            }
        }
        return result;
    }
};