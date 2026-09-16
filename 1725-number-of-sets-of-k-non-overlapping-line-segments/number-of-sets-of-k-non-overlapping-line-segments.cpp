class Solution {
public:
    int mod=1e9+7;
    vector<vector<int>>dp;

    int solve(int start,int k,int &n){
        if(k==0)return 1;
        if(n-start < k+1)return 0;
        if(dp[start][k]!=-1)return dp[start][k];
        int ans=0;
        ans=(ans+solve(start+1,k,n))%mod;
        for(int i=start+1;i<n;i++){
            ans=(ans+solve(i,k-1,n))%mod;
        }
        return dp[start][k]=ans;
    }
    int numberOfSets(int n, int k) {
        dp.resize(n+1,vector<int>(n+1,-1));
        return solve(0,k,n);
    }
};