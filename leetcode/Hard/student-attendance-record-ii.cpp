// Problem: Student Attendance Record II
// Platform: leetcode
// Rating/Difficulty: Hard
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/student-attendance-record-ii/
// Solved on: 2026-10-26T14:44:10.716Z

class Solution {
public:
    int mod=1e9+7;
    int solve(int n,int a,int lc,vector<vector<vector<int>>>&dp){
        if(n==0)return 1;
        if(dp[n][a][lc]!=-1)return dp[n][a][lc];
        int ans=0;
        //cout<<n<<endl;
        //cout<<"p"<<endl;
        ans=(ans+solve(n-1,a,0,dp))%mod;

        if(a<1){
            //cout<<n<<endl;
            //cout<<"a"<<endl;
            ans=(ans+solve(n-1,1,0,dp))%mod;
        }
        if(lc+1<3){
            //cout<<n<<endl;
            //cout<<"l"<<endl;
            ans=(ans+solve(n-1,a,lc+1,dp))%mod;
            }

        return dp[n][a][lc]=ans%mod;
    }
    int checkRecord(int n) {
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(4,-1)));
        return solve(n,0,0,dp);
    }
};