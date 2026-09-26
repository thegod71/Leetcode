class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string key="";
        string ans="";
        bool on=true;
        unordered_map<string,string>mp;
        for(auto i:knowledge){
            mp[i[0]]=i[1];
        }
        for(auto ch:s){
            if(ch=='(')on=false;
            else if(ch==')'){
                if(mp.find(key)!=mp.end()){
                    ans+=mp[key];
                }
                else ans+="?";
                key="";
                on=true;
            }
            else if(on)ans+=ch;
            else key+=ch;
        }
        return ans;
    }
};