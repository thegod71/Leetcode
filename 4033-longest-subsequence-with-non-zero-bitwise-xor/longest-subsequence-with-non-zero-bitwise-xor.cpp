class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        bool nonzero=false;
        int tot=0;
        for(auto i:nums){
            tot^=i;
            if(i>0)nonzero=true;
        }
        int len=nums.size();
        if(tot>0)return len;
        if(nonzero)return len-1;
        return 0;
    }
};