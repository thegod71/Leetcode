class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total=0;
        for(auto i:nums)total+=i;
        int tar=total-x;
        if(tar<0)return -1;
        if(tar==0)return nums.size();
        int sum=0,left=0;
        int ans=-1;
        for(int right=0;right<nums.size();right++){
            sum+=nums[right];
            while(sum> tar && left<=right){
                sum-=nums[left];
                left++;
            }
            if(sum==tar){
                ans=max(ans,right-left+1);
            }
        }
        return ans==-1?-1:nums.size()-ans;
    }
};