// Problem: Maximize the Confusion of an Exam
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/maximize-the-confusion-of-an-exam/
// Solved on: 2026-10-04T18:12:48.029Z

class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int i=0;int j=0;
        int ans = 0;
        int n = s.size();
        int temp = k;
        while(j<n){
            if(s[j]=='T'){
                ans=max(ans,j-i+1);
                j++;
            }
            else{
                if(k>0){
                    ans=max(ans,j-i+1);
                    j++;k--;
                }
                else{
                    
                    while(k<=0){
                        if(s[i++]=='F')k++;
                    }
                    k--;
                    ans=max(ans,j-i+1);
                    j++;
                }
            }
            cout<<ans<<endl;
        }
        cout<<ans<<endl;
        i=0;j=0;
        k=temp;
        while(j<n){
            if(s[j]=='F'){
                ans=max(ans,j-i+1);
                j++;
            }
            else{
                if(k>0){
                    ans=max(ans,j-i+1);
                    j++;k--;
                }
                else{
                    
                    while(k<=0){
                        if(s[i++]=='T')k++;
                    }
                    k--;
                    ans=max(ans,j-i+1);
                    j++;
                }
            }
            cout<<ans<<endl;
        }
        return ans;
    }
};