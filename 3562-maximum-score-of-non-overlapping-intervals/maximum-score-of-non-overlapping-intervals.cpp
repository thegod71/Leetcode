class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        vector<vector<int>>arr;
        int n=intervals.size();
        for(int i=0;i<n;i++){
            arr.push_back({intervals[i][1], intervals[i][0], intervals[i][2], i});
        }
        sort(arr.begin(),arr.end());
        vector<vector<long long int>>dp(n+2,vector<long long int>(5,0));
        vector<vector<vector<int>>> index(n+1,vector<vector<int>>(5));
        for(int i=1;i<=n;i++){
            int left=arr[i-1][1];
            int current_index=arr[i-1][3];
            int weight=arr[i-1][2];
            int p=0;
            int l=0,h=i-2;
            while(l<=h){
                int mid=l+(h-l)/2;
                if(arr[mid][0] < left){
                    p=mid+1;
                    l=mid+1;
                }
                else h=mid-1;
            }
            for(int j=1;j<5;j++){
                dp[i][j]=dp[i-1][j];
                index[i][j]=index[i-1][j];
                long long take=weight+dp[p][j-1];
                vector<int>take_index=index[p][j-1];
                take_index.push_back(current_index);
                sort(take_index.begin(),take_index.end());

                if(dp[i][j] < take || (dp[i][j]==take && take_index< index[i][j])){
                    dp[i][j]=take;
                    index[i][j]=take_index;
                }
            }
        }
        return index[n][4];
    }
};