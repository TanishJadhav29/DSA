// Problem: Minimum Insertions to Balance a Parentheses String
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/
// Solved on: 2026-10-09T11:55:07.246Z

class Solution {
public:
    int minInsertions(string s) {
        int opbcnt=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                opbcnt++;
            }else{
                if(opbcnt==0){
                   if(i+1<s.size() && s[i+1]==')'){
                        ans++;i++;
                    }else{
                        ans+=2;
                    } 
                }else{
                    if(i+1<s.size() && s[i+1]==')'){
                        opbcnt--;i++;
                    }else{
                        ans++;opbcnt--;
                    }
                }
            }
        }
        return ans+2*opbcnt;
    }
};