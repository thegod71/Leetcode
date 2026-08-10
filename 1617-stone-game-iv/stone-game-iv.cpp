class Solution {
public:
vector<int>arr;
unordered_map<int,bool>dp;
bool solve(int n){
    if(n<=0){
        return false;
    }
    if(dp.find(n)!=dp.end())return dp[n];
    for(auto sq:arr){
        if(sq>n)break;
        if(solve(n-sq)==false){
            return dp[n]=true;
        }
    }
    return dp[n]=false;
}
    bool winnerSquareGame(int n) {
        for(int i=1;i*i<=n;i++){
            arr.push_back(i*i);
        }
        return solve(n);
    }
};