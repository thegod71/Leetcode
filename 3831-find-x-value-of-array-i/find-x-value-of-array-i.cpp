class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long >ans(k,0);
        vector<long long > prev(k,0);
        for(auto x: nums){
            vector<long long>curr(k,0);
            curr[x%k]++;
            long long r=x%k;
            for(int i=0;i<k;i++){
                long long newr=(i*r)%k;
                curr[newr]+=prev[i];
            }
            for(int i=0;i<k;i++){
                ans[i]+=curr[i];
            }
            prev=curr;
        }
        return ans;
    }
};