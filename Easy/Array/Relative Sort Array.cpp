class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> order;
        
        // Create a mapping from the elements in arr2 to their order
        for (int i = 0; i < arr2.size(); ++i) {
            order[arr2[i]] = i;
        }
        
        // Custom comparator
        auto comparator = [&order](int a, int b) {
            auto it_a = order.find(a);
            auto it_b = order.find(b);
            
            if (it_a != order.end() && it_b != order.end()) {
                return it_a->second < it_b->second;
            }
            if (it_a != order.end()) {
                return true;
            }
            if (it_b != order.end()) {
                return false;
            }
            return a < b;
        };
        
        // Sort arr1 using the custom comparator
        sort(arr1.begin(), arr1.end(), comparator);
        
        return arr1;
        
    }
};
