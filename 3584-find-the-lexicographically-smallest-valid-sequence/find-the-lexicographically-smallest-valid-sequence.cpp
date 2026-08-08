class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        int i=n-1,j=m-1;
        vector<int>last_occur(m,-1);
        while(i>=0 && j>=0){
            if(word1[i]==word2[j]){
                last_occur[j--]=i;
            }
            i--;
        }
        vector<int>ans;
        bool isused=false;
        j=0;
        for(int i=0;i<n && j< m;i++){
            if(word1[i]==word2[j]){
                ans.push_back(i);
                j++;
            }
            else if(!isused && (j==m-1 || i<last_occur[j+1])){
                ans.push_back(i);
                j++;
                isused=true;
            }
        }
        return j==m? ans: vector<int>();
    }
};