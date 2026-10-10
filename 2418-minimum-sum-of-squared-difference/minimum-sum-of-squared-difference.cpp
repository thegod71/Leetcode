class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long total=(long long)k1+k2;
        vector<long long>count_diff(1e5+10,0);
        int max_diff=INT_MIN;
        long long sum=0;
        for(int i=0;i<nums1.size();i++){
            int diff=abs(nums1[i]-nums2[i]);
            sum+=diff;
            count_diff[diff]++;
            max_diff=max(max_diff,diff);
         }
        if(total>=sum)return 0;
        for(int i=max_diff; i> 0 && total>0 ;i--){
            if(count_diff[i]==0)continue;
            else if(total>count_diff[i]){
                count_diff[i-1]+=count_diff[i];
                total-=count_diff[i];
                count_diff[i]=0;
            }
            else {
                count_diff[i]-=total;
                count_diff[i-1]+=total;
                total=0;
            }
        }
        long long ans=0;
        for(int i=max_diff;i>0;i--){
           // cout<<count_diff[i]<<" "<<i<<endl;
            ans+=(count_diff[i]*i*i);
            //cout<<ans;
        }
        return ans;
    }
};