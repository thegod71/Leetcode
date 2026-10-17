class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<vector<int>>arr;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int val=nums[i];
            int sum=0;
            while(val!=0){
                sum+=(val%10);
                val=val/10;
            }
            if(val<0)sum+=val;
            mp[nums[i]]=i;
            arr.push_back({sum,nums[i],i});
        }
        sort(arr.begin(),arr.end(),[](const vector<int>& a, const vector<int>& b){
            if(a[0]==b[0]){
                return a[1] < b[1];
            }
            return a[0]<b[0];
        });
       
        int ans=0;
    
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=arr[i][1]){
                int index=mp[arr[i][1]];
                int val=nums[i];
                swap(nums[i],nums[index]);
                mp[val]=index;

               // cout<<mp[nums[i]]<<" "<<nums[i]<<endl;
                ans++;
            }
        }
        return ans;
    }
};