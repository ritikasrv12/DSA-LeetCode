class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
         return atMostKDistinct(nums, k) - atMostKDistinct(nums, k - 1);
    }
    
private:
    int atMostKDistinct(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;
        int count = 0;
        int left = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            if (frequency[nums[right]] == 0) {
                k--;
            }
            frequency[nums[right]]++;
            
            while (k < 0) {
                frequency[nums[left]]--;
                if (frequency[nums[left]] == 0) {
                    k++;
                }
                left++;
            }
            
            count += right - left + 1;
        }
        
        return count;
        
    }
};
