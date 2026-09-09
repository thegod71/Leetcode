class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000)return 0;
        vector<pair<long long,long long>>arr;
        arr.push_back({1000,999999});
        arr.push_back({1000000,999999999});
        arr.push_back({1000000000,999999999999});
        arr.push_back({1000000000000,999999999999999});
        arr.push_back({1000000000000000,LONG_MAX});

        long long int ans=0;
        int mul=1;
        for(auto i :arr){
            long long l=i.first;
            long long r=i.second;
            if(n<l)return ans;
            long long v1=n-l+1;
            if(n>=r){
                long long v2=n-r;
                long long diff=v1-v2;
                long long val=mul*diff*1LL;
                ans+=val;
            }
            else {
                long long val=mul*v1*1LL;
                 return ans+=val;
            }
            mul++;
        }
        return ans;
    }
};