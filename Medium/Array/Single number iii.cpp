class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            res ^= nums[i];
        }
        
        // Correct the line to avoid signed overflow
        unsigned int mask = res & static_cast<unsigned int>(-res);
        
        int first = 0;
        for(int i = 0; i < nums.size(); i++) {
            if((mask & nums[i]) != 0) {
                first ^= nums[i];
            }
        }
        
        int second = res ^ first;
        
        return {first, second};
        
    }
};
