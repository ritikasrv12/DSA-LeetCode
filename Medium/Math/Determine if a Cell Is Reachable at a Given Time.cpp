class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int mx=abs(sx-fx)+abs(sy-fy);
        int mn=min(abs(sx-fx),abs(sy-fy))+abs(abs(sx-fx)-abs(sy-fy));
        if(sx==fx && sy==fy && t==1){
            return 0;
        }
        if(t>=mn){
            return 1;
        }
        return 0;
        
    }
};
