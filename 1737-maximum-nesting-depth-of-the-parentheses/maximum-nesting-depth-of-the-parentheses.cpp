class Solution {
public:
    int maxDepth(string s) {
        int take=0,ans=0;
        for(auto i:s){
            if(i==')')take--;
            else if(i=='(')take++;
            ans=max(take,ans);
        }
        return ans;
    }
};