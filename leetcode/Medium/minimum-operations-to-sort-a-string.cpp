// Problem: Minimum Operations to Sort a String
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/minimum-operations-to-sort-a-string/
// Solved on: 2026-10-21T02:10:46.530Z

class Solution {
public:
    int minOperations(string s) {
      string temp = s;
      sort(temp.begin(),temp.end());
      if(s.size()<2)return 0;
      if(s.size()==2 && temp!=s)return -1;
      if(s==temp)return 0;
      string k1 = s;string k2=s;
      sort(k1.begin(),k1.begin()+s.size()-1);
      sort(k2.begin()+1,k2.end());
      cout<<s<<"\n"<<k1<<"\n"<<k2<<"\n\n";
      if(temp==k1 || temp==k2)return 1;
      sort(k2.begin(),k2.begin()+s.size()-1);
      sort(k1.begin()+1,k1.end());
      cout<<s<<"\n"<<k1<<"\n"<<k2<<"\n\n";
      if(temp==k1 || temp==k2)return 2;
      cout<<s<<"\n"<<k1<<"\n"<<k2<<"\n\n";
      return 3;
    }
};