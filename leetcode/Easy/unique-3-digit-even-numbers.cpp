// Problem: Unique 3-Digit Even Numbers
// Platform: leetcode
// Rating/Difficulty: Easy
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/unique-3-digit-even-numbers/
// Solved on: 2026-09-11T04:44:01.945Z

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int>cnt(10,0);
        for(int i=0;i<digits.size();i++){
            cnt[digits[i]]++;
        }
        int ans=0;
        for(int i=0;i<9;i+=2){
            if(cnt[i]>0){
                cnt[i]--;
                for(int j=1;j<=9;j++){
                    int c=0;
                    if(cnt[j]>0){
                        cnt[j]--;
                        for(int k=0;k<=9;k++){
                            if(cnt[k]>0)c++;
                        }
                        ans+=c;
                        cnt[j]++;
                    }
                }
                cnt[i]++;
            }
        }
        return ans;
    }
};