class Solution {
public:
    bool checkValidString(string s) {
        int maxi=0,mini=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                maxi++;
                mini++;
            }
            else if(s[i]==')'){
                maxi--;
                mini=max(0,mini-1);
            }
            else {
                maxi++;
                mini=max(0,mini-1);
            }
            if(maxi<0)return false;
        }
        return mini==0;
    }
};