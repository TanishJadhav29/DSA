// Problem: Permutation Sequence
// Platform: leetcode
// Rating/Difficulty: Hard
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/permutation-sequence/
// Solved on: 2026-10-13T13:50:55.848Z

class Solution {
public:
    int fac(int n){
        int ans=1;
        for(int i=n;i>=1;i--)ans*=i;
        return ans;
    }
    string solve(int n,int k,vector<int>&used,string ans){

        for(int i=1;i<=n;i++){
            if(used[i])continue;
            int unusedcnt=0;
            for(int j=1;j<=n;j++){
                if(used[j] || j==i)continue;
                unusedcnt++;
            }
            int temp = fac(unusedcnt);
            if(temp>=k){
                used[i]=1;
                ans+='0'+i;
                return solve(n,k,used,ans);
            }
            k-=temp;
        }
        return ans;
    }
    string getPermutation(int n, int k) {
        vector<int>used(n+1,0);
        return solve(n,k,used,"");
    }
};