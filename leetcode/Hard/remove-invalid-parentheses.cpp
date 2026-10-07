// Problem: Remove Invalid Parentheses
// Platform: leetcode
// Rating/Difficulty: Hard
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/remove-invalid-parentheses/
// Solved on: 2026-10-07T18:46:19.743Z

class Solution {
public:
    bool check(string temp){
        int opcnt=0;
        for(int i=0;i<temp.size();i++){
            if(opcnt<0)return false;
            if(temp[i]=='(')opcnt++;
            else if(temp[i]==')'){
                if(opcnt<=0)return false;
                opcnt--;
            }
        }
        if(opcnt==0)return true;
        return false;
    }
    int maxsize=0;
    void solve(int i,int n,string temp,string s,set<string>&ans,map<string,map<int,bool>>&mp){
        //cout<<i<<endl;
        if(i>=n){
            //cout<<temp<<" "<<i<<"first"<<endl;
            if(check(temp)){
                //cout<<"valid "<<temp<<" "<<maxsize<<endl;
                if(maxsize<temp.size()){
                    ans.clear();
                    ans.insert(temp);
                    maxsize=temp.size();
                }else if(maxsize==temp.size()){
                    ans.insert(temp);
                }
            }
            return;
        }
        if(mp[temp][i]==1){
            cout<<temp<<" "<<i<<"repeat"<<endl;
            return;
        }
        if(s[i]!='(' && s[i]!=')'){
            mp[temp][i]=1;
            temp.push_back(s[i]);
            solve(i+1,n,temp,s,ans,mp);
        }else{
            mp[temp][i]=1;
            solve(i+1,n,temp,s,ans,mp);
            temp.push_back(s[i]);
            solve(i+1,n,temp,s,ans,mp);
            temp.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        set<string>ans;
        maxsize=0;
        map<string,map<int,bool>>mp;
        solve(0,s.size(),"",s,ans,mp);
        for(auto it:ans)cout<<it<<endl;
        vector<string>res;
        for(auto it:ans)res.push_back(it);
        return res;
    }
};