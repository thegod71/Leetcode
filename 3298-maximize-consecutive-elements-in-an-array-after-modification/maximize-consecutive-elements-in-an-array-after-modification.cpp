class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>dp(1e6+2,0);
        int ans=INT_MIN;
        for(auto val:nums){
            dp[val+1]=dp[val]+1;
            dp[val]=dp[val-1]+1;
            ans=max(ans,max(dp[val],dp[val+1]));
        }
        return ans;
    }
};