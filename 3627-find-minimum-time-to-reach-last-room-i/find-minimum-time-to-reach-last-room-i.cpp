class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        int n=moveTime.size();
        int m=moveTime[0].size();
        pq.push({0,0,0});
        vector<int>arr={-1,0,1,0,-1};
        vector<vector<bool>>visit(n,vector<bool>(m,false));
        visit[0][0]=true;
        while(!pq.empty()){
            auto i=pq.top();
            pq.pop();
            int val=i[0];
            int x=i[1];
            int y=i[2];
            if(x==n-1 && y==m-1)return val;
            for(int j=0;j<4;j++){
                int newx=x+arr[j];
                int newy=y+arr[j+1];
                if(newx>=0 && newy>=0 && newx<n && newy<m && visit[newx][newy]==false){
                    visit[newx][newy]=true;
                    int value=max(moveTime[newx][newy],val);
                    pq.push({value+1,newx,newy});
                }
            }
        }
        return 0;
    }
};