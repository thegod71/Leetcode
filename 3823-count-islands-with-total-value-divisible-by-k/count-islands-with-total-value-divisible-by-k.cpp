class Solution {
public:
    vector<int>fx={-1,0,1,0};
    vector<int>fy={0,1,0,-1};
    void dfs(vector<vector<bool>>&visit,vector<vector<int>>&grid,int &row,int &col,int i,int j,long long int &sum){
        sum+=grid[i][j];
        visit[i][j]=true;
        for(int k=0;k<4;k++){
            int newr=i+fx[k];
            int newc=j+fy[k];
            if(newr<row && newc<col && newr>=0 && newc>=0 && !visit[newr][newc] && grid[newr][newc]!=0){
                dfs(visit,grid,row,col,newr,newc,sum);
            }
        }
        return ;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<bool>>visit(row,vector<bool>(col,false));
        int ans=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]!=0 && !visit[i][j]){
                    long long int sum=0;
                    dfs(visit,grid,row,col,i,j,sum);
                    if(sum%k==0)ans++;
                }
            }
        }
        return ans;
    }
};