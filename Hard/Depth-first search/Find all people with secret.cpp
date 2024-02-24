class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int, int>>> g(n);
        for (auto &meeting : meetings){
            g[meeting[0]].push_back({meeting[1], meeting[2]});
            g[meeting[1]].push_back({meeting[0], meeting[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(n);
        pq.push({0,0});
        pq.push({0, firstPerson});
        while (!pq.empty())
        {
            auto [t,x] = pq.top();
            pq.pop();
            if (vis[x]) continue;
            vis[x] = 1;
            for (auto &it : g[x])
            {
                if (vis[it.first]) continue;
                if (it.second >= t)
                pq.push({it.second, it.first});
            }
        }
        vector<int> ans;
        for (int i=0; i<n; i++)
        if (vis[i])
        ans.push_back(i);
        return ans;
        
    }
};
