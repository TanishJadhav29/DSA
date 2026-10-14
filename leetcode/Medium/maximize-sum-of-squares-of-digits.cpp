// Problem: Maximize Sum of Squares of Digits
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/maximize-sum-of-squares-of-digits/
// Solved on: 2026-10-14T02:32:26.903Z

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans="";
        if(num*9<sum)return "";
        for(int i=0;i<num;i++){
            if(sum/9>=1){
                ans+='9';
                sum-=9;
                }
            else{
                ans+='0'+sum;
                sum=0;
            }
            //cout<<ans<<endl;
        }
        return ans;
    }
};