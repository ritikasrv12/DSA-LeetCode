class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>> q;
        const int n = heights.size();
        for(int i=1; i<n; i++){
            if(heights[i] <= heights[i-1]) continue;
            q.push(heights[i] - heights[i-1]);
            if(q.size() > ladders){
                bricks -= q.top();
                q.pop();
                if(bricks < 0) return i- 1;
            }
            
        }
       return n-1; 
    }
};
