// Problem: Minimum Window Substring
// Platform: leetcode
// Rating/Difficulty: Hard
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/minimum-window-substring/
// Solved on: 2026-11-02T09:38:17.466Z

class Solution {
public:
    bool check(vector<int>freq1,vector<int>freq,int i,int j){
        //cout<<i<<" "<<j;
        for(int i=0;i<52;i++){
            if(freq[i]>0 && freq[i]>freq1[i]){
                //cout<<" false"<<endl;
                return false;}
        }
        //cout<<" true"<<endl;
        return true;
    }
    string minWindow(string s, string t) {
        vector<int>freq(52,0);
        for(int i=0;i<t.size();i++){
            if('a'<=t[i] && t[i]<='z')freq[t[i]-'a']++;
            else freq[26+t[i]-'A']++;
        }
        int i=0;int j=0;
        int st = -1;int ed = -1;
        vector<int>freq1(52,0);
        while(j<s.size() && i<=j){
            if('a'<=s[j] && s[j]<='z')freq1[s[j]-'a']++;
            else freq1[26+(s[j]-'A')]++;
            while(i<=j && check(freq1,freq,i,j)){
                ///cout<<s.substr(i,j-i+1)<<endl;
                if(st==-1 || ed-st+1>j-i+1){
                    //cout<<ed-st+1<<" "<<j-i+1<<endl;
                    st=i;ed=j;}
                if('a'<=s[i] && s[i]<='z')freq1[s[i]-'a']--;
                else freq1[26+(s[i]-'A')]--;
                i++;
            }
            j++;
        }
        if(st==-1)return "";
        cout<<st<<" "<<ed<<" "<<s.substr(st,ed-st+1)<<endl;
        return s.substr(st,ed-st+1);
    }
};