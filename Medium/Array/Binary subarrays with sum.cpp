class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count = 0;
        int sum = 0;
        std::unordered_map<int, int> prefixSumFrequency;

        for (int num : nums) {
            prefixSumFrequency[sum]++;
            sum += num;
            count += prefixSumFrequency[sum - goal];
        }

        return count;
        
    }
};
