class Solution {
public:
    string reverseParentheses(string s) {
        stack<string>st;
        for(auto i:s){
            string ch=string(1,i);
            if(i==')'){
                string s1;
                while(!st.empty()){
                    string s2=st.top();
                    st.pop();
                    if(s2=="(")break;
                    else s1+=s2;
                }
                cout<<s1;
                reverse(s1.begin(),s1.end());
                if(s1.size()!=0)st.push(s1);
            }
            else st.push(ch);
        }
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};