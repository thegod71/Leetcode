class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int sum=0,i=0,j=0;
        int len=INT_MAX;
        int n=arr.size();
        vector<int>prefix(n,INT_MAX),suffix(n,INT_MAX);
        while(i<arr.size()){
            sum+=arr[i];
            while(j<i && sum>target){
                sum-=arr[j];
                j++;
            }
            if(sum==target){
                int l=i-j+1;
                len=min(len,l);
               
            }
             prefix[i]=len;
            i++;
        }
        len=INT_MAX;
        sum=0,j=n-1,i=n-1;
        while(i>=0){
            sum+=arr[i];
             while(j>i && sum>target){
                sum-=arr[j];
                j--;
            }
           if(sum==target){
                int l=j-i+1;
                len=min(len,l);
            }
            suffix[i]=len;
            i--;
        }
        // if(sum==target){
        //     suffix[0]=len;
        // }
        int ans=INT_MAX;
        for(int i=0;i+1<n;i++){
            cout<<prefix[i]<<" "<<suffix[i]<<" "<<endl;
            if(prefix[i]!=INT_MAX && suffix[i+1]!=INT_MAX){
                ans=min(ans,prefix[i]+suffix[i+1]);
            }
        }

        return ans==INT_MAX ?-1 :ans;
    }
};