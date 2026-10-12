class Solution {
public:
    int mod=1e9+7;
    int maxSum(vector<int>& nums, int k) {
        vector<long long>arr(32,0);
        for(auto num:nums){
            for(int i=0;i<32;i++){
                if((num&(1<<i))!=0)arr[i]++;
            }
        }
       
       long long int ans=0;
        for(int i=0;i<k;i++){
            long long int number=0;
            for(int i=0;i<32;i++){
                if(arr[i]>0){
                    number |= (1LL << i);
                    arr[i]--;
                }
            }
            long long num = (number * number) % mod;
            ans=(1ll*ans+num)%mod;
        }
        return ans;
    }
};