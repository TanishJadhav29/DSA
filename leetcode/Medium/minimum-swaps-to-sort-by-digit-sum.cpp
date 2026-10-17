// Problem: Minimum Swaps to Sort by Digit Sum
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/minimum-swaps-to-sort-by-digit-sum/
// Solved on: 2026-10-17T05:49:45.424Z

class Solution {
public:
    int getdigsum(int n) {
    n = abs(n);
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>m;
        unordered_map<int,int>mp;
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            int digsum = getdigsum(nums[i]);
            v.push_back({digsum,nums[i]});
            m[nums[i]]=i;
            mp[i]=nums[i];
        }
        int cnt=0;
        sort(v.begin(),v.end());
        //for(int i=0;i<n;i++)cout<<v[i].second<<" ";
        //cout<<endl;
        for(int i=n-1;i>=0;i--){
            int idx = m[v[i].second];
            //cout<<i<<" "<<idx<<" "<<v[i].second<<endl;
            if(idx==i)continue;
            int ele = mp[i];
            //cout<<"ele "<<ele<<endl;
            m[ele]=idx;
            mp[idx]=ele;
            cnt++;
        }

        return cnt;
    }
};