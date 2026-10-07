class Solution {
public:
void solve(unordered_set<string>&ans,string &output,int bal,int open,int close,int index,string &s){
    if(index>=s.length()){
        if(open==0 && close==0 && bal==0){
            ans.insert(output);
        } 
        return;
    }
if(s[index] !=')' && s[index] !='('){
    output.push_back(s[index]);
    solve(ans,output,bal,open,close,index+1,s);
    output.pop_back();
}
else{
     if(s[index]=='('){
        if(open >0){
            solve(ans,output,bal,open-1,close,index+1,s);
        }
        output.push_back(s[index]);
        solve(ans,output,bal+1,open,close,index+1,s);
        output.pop_back();
     }
     else{
        if(close>0){
            solve(ans,output,bal,open,close-1,index+1,s);
        }
        if(bal>0){
            output.push_back(s[index]);
            solve(ans,output,bal-1,open,close,index+1,s);
            output.pop_back();
        }
     }
}
   
}
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string>ans;
        int invalidopen=0;
        int invalidclosed=0;
        int bal=0;
        string output="";
        for(auto ch:s){
            if(ch=='('){
                invalidopen++;
            }
            else if(ch==')'){
                if(invalidopen>0){
                  invalidopen--;
                }
                else{
                    invalidclosed++; 
                }
            }
        }
        int index=0;
        solve(ans,output,bal,invalidopen,invalidclosed,index,s);
 vector<string>gans(ans.begin(),ans.end());
    return gans;
    }
};