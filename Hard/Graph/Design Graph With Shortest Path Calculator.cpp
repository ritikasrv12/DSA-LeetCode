#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Graph {
public:
    int n;
    vector<vector<pair<int, int>>> adj;
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        adj.resize(n);
        for (auto& edge : edges) {
            adj[edge[0]].emplace_back(edge[1], edge[2]);
        }
        
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].emplace_back(edge[1], edge[2]);
        
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> dist(n, INT_MAX);
        dist[node1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, node1});

        while (!pq.empty()) {
            int u = pq.top().second;
            int cost = pq.top().first;
            pq.pop();

            if (u == node2) {
                return dist[node2];
            }

            for (auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        return -1; // No path found
        
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
