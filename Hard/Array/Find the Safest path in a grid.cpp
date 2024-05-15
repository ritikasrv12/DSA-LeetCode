bool check(vector<vector<int>>&safety,int lim){
    //this will check if there is path with atleast safeness lim

    if(safety[0][0] < lim)return false;
    queue<pair<int,int>>bfs;
    bfs.push({0,0});
    
    int n = safety.size();
    vector<vector<bool>>vis(n,vector<bool>(n,0));
    vis[0][0] = 1;
    
    while(!bfs.empty()){
            pair<int,int>temp = bfs.front();
            bfs.pop();
            int x = temp.first;
            int y = temp.second;
         
         //if I am able to reach last cell it means there is a path
            if(x == n-1 && y == n-1)return true;
            
            
            //I can go down if not visited and safeness atleast lim
            if((x+1)<n){
                if(vis[x+1][y] == false && safety[x+1][y] >= lim){
                    vis[x+1][y] = 1;
                    bfs.push({x+1,y});
                }
            }
            
            //I can go right if not visited and safeness atleast lim
            if((y+1)<n){
                if(vis[x][y+1] == false && safety[x][y+1] >= lim){
                    vis[x][y+1] = 1;
                    bfs.push({x,y+1});
                }
            }
            
            //I can go up if not visited and safeness atleast lim
            if((x-1)>=0){
                if(vis[x-1][y] == 0 && safety[x-1][y] >= lim ){
                    vis[x-1][y] =  1;
                    bfs.push({x-1,y});
                }
            }
            
            //I can go left if not visited and safeness atleast lim
             if((y-1)>=0){
                if(vis[x][y-1] == 0 && safety[x][y-1] >= lim){
                    vis[x][y-1] = 1;
                    bfs.push({x,y-1});
                }
            }
        }

    //I am unable to reach to end
    return false;
}

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        //creating a 2d grid for safeness of every cell
        vector<vector<int>>safety(n,vector<int>(m,INT_MAX));
        
        queue<pair<pair<int,int>,int>>bfs;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]){
                    //we will start from every thief cell
                    bfs.push({{i,j},0});
                    safety[i][j] = 0;
                }
            }
        }
        
        int mx = 0;
        while(!bfs.empty()){
            pair<pair<int,int>,int>temp = bfs.front();
            bfs.pop();
            int x = temp.first.first;
            int y = temp.first.second;
            int val = temp.second;
            mx = max(mx,val);
            
            //I can go to down cell if the safeness there is > than val
            if((x+1)<n){
                if(safety[x+1][y] > (val+1)){
                    safety[x+1][y] = val+1;
                    bfs.push({{x+1,y},val+1});
                }
            }
            
            //I can go to right cell if the safeness there is > than val
            if((y+1)<n){
                if(safety[x][y+1] > (val+1)){
                    safety[x][y+1] = val+1;
                    bfs.push({{x,y+1},val+1});
                }
            }
            
            //I can go to up cell if the safeness there is > than val
            if((x-1)>=0){
                if(safety[x-1][y] > (val+1)){
                    safety[x-1][y] = val+1;
                    bfs.push({{x-1,y},val+1});
                }
            }
            //I can go to left cell if the safeness there is > than val
             if((y-1)>=0){
                if(safety[x][y-1] > (val+1)){
                    safety[x][y-1] = val+1;
                    bfs.push({{x,y-1},val+1});
                }
            }
        }
        
        //I can do a binary search on value
        int start = 0,end = mx,mid = (start+end)/2;
        
        int ans = 0;
        
        while(start<=end){
            //we need the mid to be smallest value possible
            if(check(safety,mid)){
                ans = max(ans,mid);
                start = mid+1;
            }
            else end = mid-1;
            mid = (start+end)/2;
        }
        
        
        return ans;
        
    }
};
