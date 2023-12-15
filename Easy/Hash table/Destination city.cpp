class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> outgoingCities;

        // Add source cities to the set
        for (const auto& path : paths) {
            outgoingCities.insert(path[0]);
        }

        // Find the destination city
        for (const auto& path : paths) {
            if (outgoingCities.find(path[1]) == outgoingCities.end()) {
                return path[1];
            }
        }

        // The function should always return a valid result, so this line should never be reached.
        return "";
        
    }
};
