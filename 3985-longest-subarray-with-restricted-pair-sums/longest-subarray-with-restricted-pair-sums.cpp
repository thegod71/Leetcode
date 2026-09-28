class Solution {
public:
    bool solve(vector<int>&freq,int x){
        for(int a=1;a<=500;a++){
            if(freq[a]>0){
            int val=x+a;
            int val1=x-a;
            if(val1==a && freq[a]>1){
               
                return false;
            }
            else if( val1> 0 && val1!=a && freq[val1]>0){
                 cout<<x;
                return false;
            }
            if(val <=500 && freq[val]>0){
               
                return false;
            }
            }
        }
        return true;
    }
    int maxSubarray(vector<int>& nums) {
        vector<int>freq(501,0);
        int ans=INT_MIN;
        int l=0,r=0;
        while(r<nums.size()){
            while( l<r && !solve(freq,nums[r])){
                freq[nums[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
            freq[nums[r]]++;
            r++;
        }
        return ans;
    }
};