class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int total_satisfied = 0;
        
        // Calculate the initial number of satisfied customers without using the secret technique.
        for (int i = 0; i < n; ++i) {
            if (!grumpy[i]) {
                total_satisfied += customers[i];
            }
        }
        
        // Calculate the number of potentially satisfied customers if we use the technique in the first `minutes` window.
        int max_satisfied_with_technique = 0;
        for (int i = 0; i < minutes; ++i) {
            if (grumpy[i]) {
                max_satisfied_with_technique += customers[i];
            }
        }
        
        // Use a sliding window to find the maximum number of potentially satisfied customers.
        int current_satisfied_with_technique = max_satisfied_with_technique;
        for (int i = minutes; i < n; ++i) {
            if (grumpy[i]) {
                current_satisfied_with_technique += customers[i];
            }
            if (grumpy[i - minutes]) {
                current_satisfied_with_technique -= customers[i - minutes];
            }
            max_satisfied_with_technique = std::max(max_satisfied_with_technique, current_satisfied_with_technique);
        }
        
        // The result is the total satisfied customers without the technique plus the maximum possible gain from the technique.
        return total_satisfied + max_satisfied_with_technique;
        
    }
};
