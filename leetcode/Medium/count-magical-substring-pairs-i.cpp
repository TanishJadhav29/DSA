// Problem: Count Magical Substring Pairs I
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/count-magical-substring-pairs-i/
// Solved on: 2026-10-24T15:28:36.541Z

class Solution {
public:
    int countMagicalPairs(string s) {
        int n=s.size();
        vector<vector<int>>mp(n+1,vector<int>(n+1,0));
        for(int i=0;i<n;i++){
            vector<int>freq(26,0);
            int cnt=0;
            for(int j=i;j<n;j++){
                if(freq[s[j]-'a']==0){
                    freq[s[j]-'a']=1;
                    cnt++;
                }
                    mp[i][cnt]++;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int>freq(26,0);
            int cnt=0;
            for(int j=i;j<n;j++){
                if(freq[s[j]-'a']==0){
                    freq[s[j]-'a']=1;
                    cnt++;
                }
                if(mp[j+1][cnt]==0)break;
                ans+=mp[j+1][cnt];
                //cout<<i<<" "<<j<<" "<<mp[j+1][cnt]<<endl;
            }
        }
        return ans;
    }
};