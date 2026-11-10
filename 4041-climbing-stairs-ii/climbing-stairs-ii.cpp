class Solution {
public:
    unordered_map<int,int>mp;
    int solve(int &n,vector<int>&cost,int index){
        if(index==n)return 0;
        if(mp.find(index)!=mp.end())return mp[index];
        int a=INT_MAX,b=INT_MAX,c=INT_MAX;
        if(index+1 <= n){
        int x = solve(n,cost,index+1);
            if(x!=INT_MAX){
                a=1+cost[index]+x;
            }
        }
        if(index+2 <= n){
        int x = solve(n,cost,index+2);
            if(x!=INT_MAX){
                b=4+cost[index+1]+x;
            }
        }
        if(index+3 <= n){
        int x = solve(n,cost,index+3);
            if(x!=INT_MAX){
                c=9+cost[index+2]+x;
            }
        }
        return mp[index]=min(a,min(b,c));
    }
    int climbStairs(int n, vector<int>& costs) {
        return solve(n,costs,0);
    }
};