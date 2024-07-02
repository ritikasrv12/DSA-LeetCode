unordered_map<int, int> count1, count2;
        vector<int> result;
        
        // Count occurrences of each element in nums1
        for (int num : nums1) {
            count1[num]++;
        }
        
        // Count occurrences of each element in nums2
        for (int num : nums2) {
            count2[num]++;
        }
        
        // Find the intersection
        for (auto& pair : count1) {
            int element = pair.first;
            if (count2.find(element) != count2.end()) {
                int min_count = min(pair.second, count2[element]);
                for (int i = 0; i < min_count; ++i) {
                    result.push_back(element);
                }
            }
        }
        
        return result;
