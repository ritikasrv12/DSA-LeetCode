class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        
        // Combine profits and capital into a single vector of pairs for easier manipulation
        vector<pair<int, int>> projects;
        for (int i = 0; i < n; ++i) {
            projects.emplace_back(capital[i], profits[i]);
        }
        
        // Sort projects by capital requirements
        sort(projects.begin(), projects.end());
        
        // Max-heap to keep track of the most profitable projects we can start
        priority_queue<int> maxHeap;
        
        int currentCapital = w;
        int projectIndex = 0;
        
        for (int i = 0; i < k; ++i) {
            // Add all projects that can be started with the current capital to the max-heap
            while (projectIndex < n && projects[projectIndex].first <= currentCapital) {
                maxHeap.push(projects[projectIndex].second);
                ++projectIndex;
            }
            
            // If there are no more projects we can start, break early
            if (maxHeap.empty()) {
                break;
            }
            
            // Select the most profitable project we can start
            currentCapital += maxHeap.top();
            maxHeap.pop();
        }
        
        return currentCapital;
        
    }
};
