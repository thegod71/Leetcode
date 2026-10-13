class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]=abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        long long ans=0;
        int n=nums.size();
        int i=0,j=nums.size()-1;
        while(i<j){
            int num1=nums[i];
            int num2=nums[j];
            long long a=(1ll*num1*num1);
            long long b=(1ll*num2*num2);
            ans+=(b-a);
            i++;
            j--;
        }
        cout<<ans;
        if(n%2!=0){
            int num2=nums[j];
            long long a=(1ll*num2*num2);
            ans+=a;
        }
        return ans;
    }
};