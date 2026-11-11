class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        int minicost=min(costBoth,cost1+cost2);
        int minineed=min(need1,need2);
        long long ans=0;
        ans+=(1LL*minicost*minineed);
        if(minineed==need1){
            //rem=need2
            int minicost2=min(costBoth,cost2);
            int rem=need2-minineed;
            ans+=(1LL*minicost2*rem);
        }
        else{
            int minicost1=min(costBoth,cost1);
            int rem=need1-minineed;
            ans+=(1LL*minicost1*rem);
        }
        return ans;
    }
};