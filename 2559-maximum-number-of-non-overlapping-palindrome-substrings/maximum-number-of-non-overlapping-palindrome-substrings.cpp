class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n=s.size();
        vector<vector<bool>>is_Palindrome(n+1,vector<bool>(n+1,false));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j] && (j-i<2 || is_Palindrome[i+1][j-1])){
                    is_Palindrome[i][j]=true;
                }
            }
        }
        vector<int>ans(n+1,0);
        for(int i=n-1;i>=0;i--){
            ans[i]=ans[i+1];
            for(int j=i+k-1;j<n;j++){
                if(is_Palindrome[i][j])ans[i]=max(ans[i],1+ans[j+1]);
            }
        }
        return ans[0];
    }
};