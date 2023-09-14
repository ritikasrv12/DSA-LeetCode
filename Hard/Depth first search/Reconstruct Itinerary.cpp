class Solution {
public:
vector<string> ans;
    
    map<string, multiset<string>> graph;
public:
    
    void dfs(string source)
    {
        while(graph[source].size())
        {
            string x = *(graph[source].begin());
            graph[source].erase(graph[source].begin());
            dfs(x);
        }
        
        ans.push_back(source);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(int i=0; i<tickets.size(); i++)
        {
            string from = tickets[i][0];
            string to = tickets[i][1];
            graph[from].insert(to);
        }
        
        dfs("JFK");
        
        reverse(ans.begin(), ans.end());
        
        return ans; 
        
    }
};
