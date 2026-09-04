class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>mini(n);
        mini[n-1]=nums[n-1];
        int maxi=INT_MIN;
        for(int i=n-2;i>=0;i--){
            mini[i]=min(nums[i],mini[i+1]);
        }
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            int val=maxi-mini[i];
            if(val<=k)return i;
        }
    return -1;
    }
};