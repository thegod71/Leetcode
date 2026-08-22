class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0,mul=1;
        string s=to_string(n);
        for(auto i:s){
            int a=i-'0';
            sum+=a;
            mul*=a;
        }
        cout<<sum<<mul;
        sum+=mul;
        if(n%sum==0)return true;
        return false;
    }
};