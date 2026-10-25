class Solution {
public:
    vector<int>fx={-1,0,1,0};
    vector<int>fy={0,1,0,-1};
    void dfs(vector<vector<bool>>&visit,vector<vector<int>>&grid,int &row,int &col,int i,int j){
        visit[i][j]=true;
        for(int k=0;k<4;k++){
            int newr=i+fx[k];
            int newc=j+fy[k];
            if(newr<row && newc<col && newr>=0 && newc>=0 && !visit[newr][newc] && grid[newr][newc]==0){
                dfs(visit,grid,row,col,newr,newc);
            }
        }
        return ;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<bool>>visit(row,vector<bool>(col,false));
        for(int i=0;i<row;i++){
            if(grid[i][0]==0 && !visit[i][0])dfs(visit,grid,row,col,i,0);
            if(grid[i][col-1]==0 && !visit[i][col-1])dfs(visit,grid,row,col,i,col-1);
        }
        for(int i=0;i<col;i++){
            if(grid[0][i]==0 && !visit[0][i])dfs(visit,grid,row,col,0,i);
            if(grid[row-1][i]==0 && !visit[row-1][i])dfs(visit,grid,row,col,row-1,i);
        }
        int ans=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==0 && !visit[i][j]){
                    dfs(visit,grid,row,col,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};