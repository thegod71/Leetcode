class Solution {
public:
 map<pair<pair<int,int>,bool>,int>mp;
int solve(vector<int>piles,int i,int m,bool alice){
    if(i==piles.size()){
        return 0;
    }
    if(mp.find({{i,m},alice})!=mp.end()){
        return mp[{{i,m},alice}];
    }
     
    int total=0;
    int ans=(alice) ? INT_MIN:  INT_MAX;
    for(int x=1;x<=2*m;x++){
        if(i+x-1>=piles.size())break;
        total+=piles[i+x-1];
        if(alice){
            ans=max(ans,total+solve(piles,i+x,max(x,m),!alice));
        }
        else{
            ans=min(ans,solve(piles,i+x,max(x,m),!alice));
        }
    }
    mp[{{i,m},alice}]=ans;
        return  mp[{{i,m},alice}] ;
}
int tabul(vector<int>&piles){
    vector<vector<vector<int>>>dp(piles.size()+1,vector<vector<int>>(piles.size()+1,vector<int>(2,0)));
    for(int i=piles.size()-1;i>=0;i--){
        for(int m=piles.size();m>=1;m--){
            for(int alice=0;alice<=1;alice++){
                  int total=0;
    int ans=(alice) ? INT_MIN:  INT_MAX;
    for(int x=1;x<=2*m;x++){
        if(i+x-1>=piles.size())break;
        total+=piles[i+x-1];
        if(alice){
            ans=max(ans,total+ dp[i+x][max(x,m)][!alice]);
        }
        else{
            ans=min(ans,dp[i+x][max(x,m)][!alice]);
          }
       }
        dp[i][m][alice]=ans;
            }
        }
    }
   return  dp[0][1][1];
}
    int stoneGameII(vector<int>& piles) {
        
        return  tabul(piles);
    }
};