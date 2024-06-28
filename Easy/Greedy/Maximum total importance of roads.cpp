class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        // Step 1: Count the degree of each city
        vector<int> degree(n, 0);
        for (const auto& road : roads) {
            degree[road[0]]++;
            degree[road[1]]++;
        }

        // Step 2: Sort cities by degree in descending order
        vector<int> cities(n);
        iota(cities.begin(), cities.end(), 0); // Fill cities with 0 to n-1
        sort(cities.begin(), cities.end(), [&](int a, int b) {
            return degree[a] > degree[b];
        });

        // Step 3: Assign values to cities
        vector<int> cityValues(n);
        for (int i = 0; i < n; ++i) {
            cityValues[cities[i]] = n - i;
        }

        // Step 4: Calculate total importance
        long long totalImportance = 0;
        for (const auto& road : roads) {
            totalImportance += cityValues[road[0]] + cityValues[road[1]];
        }

        return totalImportance;
        
    }
};
