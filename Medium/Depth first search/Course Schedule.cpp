class Solution {
public:
bool dfs(vector<int>adj[],vector<bool>&vis,int ind,vector<bool>&vissf){
        
        if(vissf[ind]) 
            return false;
        
        if(vis[ind]) 
            return true;
        
        vis[ind] = vissf[ind] = 1;

        for(auto node:adj[ind])
            if(!dfs(adj,vis,node,vissf))
                return false;
        
        vissf[ind] = 0;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int>adj[numCourses];

        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        vector<bool>vis(numCourses,0),vissf(numCourses,0);

        for(int i=0;i<numCourses;i++){
            if(!vis[i] && !dfs(adj,vis,i,vissf))
                return false; 
        }

        return true;
    }
};
