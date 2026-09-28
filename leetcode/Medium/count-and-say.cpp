// Problem: Count and Say
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/count-and-say/
// Solved on: 2026-09-28T07:52:00.130Z

class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        for(int i=2;i<=n;i++){
            int cnt=1;
            string temp="";
            for(int j=1;j<s.size();j++){
                if(s[j]==s[j-1]){
                    cnt++;
                }else{
                    temp+=(to_string(cnt)+s[j-1]);
                    cnt=1;
                }
            }
            temp+=(to_string(cnt)+s[s.size()-1]);
            cout<<i<<" "<<temp<<endl;
            s=temp;
        }
        return s;
    }
};