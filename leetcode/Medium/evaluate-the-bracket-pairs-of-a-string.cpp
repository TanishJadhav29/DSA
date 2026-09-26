// Problem: Evaluate the Bracket Pairs of a String
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/
// Solved on: 2026-09-26T06:25:05.878Z

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans="";
        string temp="";
        int n=s.size();
        int m=knowledge.size();
        bool bracket=false;
        map<string,string>mp;

        for(int i=0;i<m;i++){
            mp[knowledge[i][0]]=knowledge[i][1];
        }

        for(int i=0;i<n;i++){
            if(s[i]>='a' && s[i]<='z'){
                if(bracket==false)ans+=s[i];
                else temp+=s[i];
            }
            else if(s[i]=='('){
                bracket=true;
            }else{
                // cout<<temp<<endl;
                if(mp.find(temp)!=mp.end())ans+=mp[temp];
                else ans+='?';
                temp="";
                bracket=false;
            }
        }
        return ans;
    }
};