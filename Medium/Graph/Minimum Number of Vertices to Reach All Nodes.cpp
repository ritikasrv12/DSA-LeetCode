class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> mp(n , 0 ) ;
        
        for(auto it :edges){
            mp[it[1]]+=1;
        }
        
        vector<int> ans;
       for(int i = 0 ; i < n ; i++){
           if(mp[i] == 0 )
               ans.push_back(i);
       }
        return ans;
        
    }
};
