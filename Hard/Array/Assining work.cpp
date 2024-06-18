class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
         vector<pair<int, int>> jobs;
        for (int i = 0; i < difficulty.size(); ++i) {
            jobs.emplace_back(difficulty[i], profit[i]);
        }
        sort(jobs.begin(), jobs.end());

        // Sort the workers by their abilities
        sort(worker.begin(), worker.end());

        int maxProfit = 0, bestProfit = 0, j = 0;
        for (int i = 0; i < worker.size(); ++i) {
            // For each worker, find the best profit they can get
            while (j < jobs.size() && jobs[j].first <= worker[i]) {
                bestProfit = max(bestProfit, jobs[j].second);
                ++j;
            }
            maxProfit += bestProfit;
        }

        return maxProfit;
        
    }
};
