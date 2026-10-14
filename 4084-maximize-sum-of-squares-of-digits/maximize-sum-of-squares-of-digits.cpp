class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(9LL*num < sum)return "";
        int nine=sum/9;
        int rem=sum%9;
        string ans="";
        ans.append(nine,'9');
        if(rem>0)ans+=(rem+'0');
        ans.append(num-ans.size(),'0');
        return ans;
    }
};