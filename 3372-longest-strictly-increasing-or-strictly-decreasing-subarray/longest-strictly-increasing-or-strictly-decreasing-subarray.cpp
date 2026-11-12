class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
       int ans=1;
       for(int i=0;i<nums.size()-1;i++){
            int j=i+1;
            while(j<nums.size() && nums[j-1] <nums[j]) j++;
            ans=max(ans,j-i);
            j=i+1;
            while(j<nums.size() && nums[j-1] > nums[j]) j++;
            ans=max(ans,j-i);
       } 
       return ans;
    }
};