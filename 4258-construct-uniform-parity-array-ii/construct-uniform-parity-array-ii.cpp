class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
       sort(nums1.begin(),nums1.end());
       if(nums1[0]%2==0){
        for(auto i:nums1){
            if(i%2!=0)return false;
        }
        return true;
       } 
       return true;
    }
};