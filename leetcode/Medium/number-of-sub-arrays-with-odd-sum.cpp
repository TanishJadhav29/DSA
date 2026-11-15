// Problem: Number of Sub-arrays With Odd Sum
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/
// Solved on: 2026-11-15T05:33:44.185Z

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int>cumsum(n);
        cumsum[0]=arr[0];
        for(int i=1;i<n;i++){
            cumsum[i]=arr[i]+cumsum[i-1];
        }
        //1 4 9
        //2 6 12
        int mod=1e9+7;
        int even=0;
        int odd=0;
        int ans=0;
        for(int i=n-1;i>=0;i--){
            int left=0;
            if(i-1>=0)left=cumsum[i-1];
            if(cumsum[i]%2==0)even++;
            else odd++;

            if((left%2)==0)(ans=(ans+odd)%mod);
            else (ans=(ans+even)%mod);
        }
        return ans;
    }
};