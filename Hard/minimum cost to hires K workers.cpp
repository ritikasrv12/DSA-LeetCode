class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> ratios; // Store wage/quality ratios
        
        // Calculate ratios and store them with corresponding worker index
        for (int i = 0; i < n; ++i) {
            double ratio = (double)wage[i] / quality[i];
            ratios.push_back({ratio, i});
        }
        
        // Sort workers based on ratios
        sort(ratios.begin(), ratios.end());
        
        priority_queue<int> pq; // Max heap to store top k qualities
        
        int sum_quality = 0;
        for (int i = 0; i < k; ++i) {
            sum_quality += quality[ratios[i].second];
            pq.push(quality[ratios[i].second]);
        }
        
        double min_cost = sum_quality * ratios[k - 1].first; // Initialize min cost
        
        // Iterate from kth worker to nth worker
        for (int i = k; i < n; ++i) {
            pq.push(quality[ratios[i].second]);
            sum_quality += quality[ratios[i].second];
            sum_quality -= pq.top(); // Remove the worker with maximum quality from the group
            pq.pop();
            
            min_cost = min(min_cost, sum_quality * ratios[i].first);
        }
        
        return min_cost;
        
    }
};
