class Solution {
public:
    int find(int val){
        string s=to_string(val);
        int ans=1;
        for(auto i:s){
            int v=i-'0';
            ans*=v;
        }
        return ans;
    }
    int smallestNumber(int n, int t) {
        for(int i=n;i<=10000;i++){
            int val=find(i);
            if(val%t==0)return i;
        }
        return -1;
    }
};