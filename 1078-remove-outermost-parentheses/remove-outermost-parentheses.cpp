class Solution {
public:
    string removeOuterParentheses(string s) {
        int depth=1;
        int l=0,r=1;
        string ans;
        while(r<s.size()){
            if(s[r]=='(')depth++;
            else depth--;
            if(depth>0)ans+=s[r];
            else {
                depth=1;
                r++;
            }
            r++;
        }
        return ans;
    }
};