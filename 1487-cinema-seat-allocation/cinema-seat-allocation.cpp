class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int,vector<int>>mp;
        for(auto i:reservedSeats){
            int row=i[0];
            int seat=i[1];
            mp[row].push_back(seat);
        }
        vector<vector<int>>nums;
        nums.push_back({2,3,4,5});
        nums.push_back({4,5,6,7});
        nums.push_back({6,7,8,9});
        int rest=n-mp.size();
        int ans=2*rest;
        for(auto i:mp){
            vector<int>arr1=i.second;
            vector<int>arr2(11,0);
            for(auto i:arr1)arr2[i]=1;
            int j=0;
            while(j<3){
                vector<int>arr3=nums[j];
                bool a=true;
                for(auto k:arr3){
                    if(arr2[k]==1){
                        a=false;
                        break;
                    }
                }
                if(a==true){
                    cout<<j<<" ";
                    ans++;
                    j+=2;
                }
                else j++;
            }
        }
        return ans;
    }
};