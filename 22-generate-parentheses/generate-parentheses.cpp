class Solution {
public:
    vector<string>ans;
    void solve(int &n,int index,int open,int close,string &s){
        if(index==n+n){
            ans.push_back(s);
            return;
        }
        if(open<n){
            s+='(';
            solve(n,index+1,open+1,close,s);
            s.pop_back();
        }
        if(close< open && close<n){
            s+=')';
            solve(n,index+1,open,close+1,s);
            s.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        string s;
        solve(n,0,0,0,s);
        return ans;
    }
};