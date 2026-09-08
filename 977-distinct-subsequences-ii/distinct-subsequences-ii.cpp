class Solution {
public:
    int mod=1e9+7;
    int distinctSubseqII(string s) {
        unordered_map<char,long long>mp;
       long long int ans=0;
        for(auto c:s){
            long long prev=ans+1;
            ans=(ans+prev-mp[c]+mod)%mod;
            mp[c]=prev;
        }
        return (int)ans;

     return ans;   
    }
};