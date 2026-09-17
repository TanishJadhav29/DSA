// Problem: Find Two Non-overlapping Sub-arrays Each With Target Sum
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/
// Solved on: 2026-09-17T16:22:19.376Z

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        vector<int>size;vector<int>idx;
        int i=0;int j=0;
        int n=arr.size();
        int sum=0;
        while(j<n){
            sum+=arr[j++];
            while(sum>target){
                sum-=arr[i++];
            }
            if(sum==target){
                size.push_back(j-i);
                idx.push_back(j-1);
            }
        }
        int s=size.size();
        vector<int>leftmin(s);
        for(int i=s-1;i>=0;i--){
            leftmin[i]=size[i];
            if(i+1<s)leftmin[i]=min(leftmin[i],leftmin[i+1]);
        }
        //for(int i=0;i<s;i++)cout<<size[i]<<" ";
        //cout<<endl;
        //for(int i=0;i<s;i++)cout<<idx[i]<<" ";
        //cout<<endl;
        //for(int i=0;i<s;i++)cout<<leftmin[i]<<" ";
        //cout<<endl;
        int ans=INT_MAX;
        //cout<<endl;
        for(int i=0;i<s;i++){
            int val1=size[i];
            int eidx1=idx[i];
            int sidx1=eidx1-val1+1;
            //cout<<"1 "<<sidx1<<" "<<eidx1<<endl;
            int l=i+1;
            int h=s-1;
            //cout<<"l->"<<l<<" "<<"h->"<<h<<endl;
            while(l<=h){
                int mid=(l+h)/2;
                int val2=size[mid];
                int eidx2=idx[mid];
                int sidx2=eidx2-val2+1;
                //cout<<"2 "<<sidx2<<" "<<eidx2<<endl;
                //check overlap
                if((sidx1<=sidx2 && sidx2<=eidx1)){
                    //cout<<"overlap->"<<sidx1<<" "<<sidx2<<" "<<eidx1<<endl;
                    l=mid+1;
                }else{
                //no overlap   
                    ans=min(ans,(val1+leftmin[mid]));
                    //cout<<"no overlap->"<<ans<<endl;
                    h=mid-1;
                }
            }
            cout<<endl;
        }
        return ans==INT_MAX?-1:ans;
    }
};