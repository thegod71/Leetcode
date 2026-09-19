class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        if(x1<=xCenter && x2>=xCenter && y1<=yCenter && y2>=yCenter)return true;


        int dist=INT_MAX;
        int smallx=min(x1,x2);
        int smally=min(y1,y2);
        int bigx=max(x1,x2);
        int bigy=max(y1,y2);
        for(int i=smally;i<=bigy;i++){
            int x=abs(xCenter-x1);
            int above=abs(xCenter-x2);
            int y=abs(yCenter-i);
            int a1=sqrt((above*above)+(y*y));    
            int a=sqrt((x*x)+(y*y));
            dist=min(dist,a);
            dist=min(dist,a1);
        }
        for(int i=smallx;i<=bigx;i++){
            int y=abs(yCenter-y1);
            int left=abs(yCenter-y2);
            int x=abs(xCenter-i);
            int a1=sqrt((left*left)+(x*x));    
            int a=sqrt((x*x)+(y*y));
            dist=min(dist,a);
            dist=min(dist,a1);
        }
        if(dist<=radius)return true;
        return false;
    }
};