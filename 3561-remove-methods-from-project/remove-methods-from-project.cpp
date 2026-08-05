class Solution {
public:
    void dfs(vector<vector<int>>&adj,int node,vector<int>&sus){
        sus[node]=1;
        for(auto i:adj[node]){
            if(sus[i]==0){
                dfs(adj,i,sus);
            }
        }
        return;
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        vector<int>sus(n,0);
        vector<int>visit(n,0);
        for(auto edge:invocations){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
        }
        dfs(adj,k,sus);
        bool all=false;
        for(int i=0;i<n;i++){
            if(all)break;
            if(sus[i]==0){
                for(auto j:adj[i]){
                    if(sus[j]==1){
                        all=true;
                        break;
                    }
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(all)ans.push_back(i);
            else{
                if(sus[i]==0)ans.push_back(i);
            }
        }
        return ans ;
    }
};