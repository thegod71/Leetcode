class Solution {
public:
     vector<int> prefix;
    vector<vector<int>> dp;

    int solve(int start, int end) {

        if(start == end)
            return 0;

        if(dp[start][end] != -1)
            return dp[start][end];

        int ans = 0;

        for(int i = start; i < end; i++) {

            int left = prefix[i + 1] - prefix[start];
            int right = prefix[end + 1] - prefix[i + 1];

            if(left < right) {
                ans = max(ans, left + solve(start, i));
            }
            else if(left > right) {
                ans = max(ans, right + solve(i + 1, end));
            }
            else {
                ans = max(ans, left + solve(start, i));
                ans = max(ans, right + solve(i + 1, end));
            }
        }

        return dp[start][end] = ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        prefix.resize(n+1,0);
        
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+stoneValue[i];
        }
        dp.assign(n, vector<int>(n, -1));
        return  solve(0,n-1);
    }
};