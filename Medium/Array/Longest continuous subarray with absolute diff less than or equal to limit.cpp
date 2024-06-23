class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
         int n = nums.size();
        int left = 0, right = 0;
        int maxLength = 0;
        
        deque<int> maxDeque, minDeque;
        
        while (right < n) {
            // Maintain the maxDeque to store the indices of the maximum values
            while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[right]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(right);
            
            // Maintain the minDeque to store the indices of the minimum values
            while (!minDeque.empty() && nums[minDeque.back()] >= nums[right]) {
                minDeque.pop_back();
            }
            minDeque.push_back(right);
            
            // Check the difference between the maximum and minimum values in the current window
            while (nums[maxDeque.front()] - nums[minDeque.front()] > limit) {
                left++;
                // Remove elements that are out of the current window
                if (maxDeque.front() < left) {
                    maxDeque.pop_front();
                }
                if (minDeque.front() < left) {
                    minDeque.pop_front();
                }
            }
            
            // Calculate the length of the current valid window
            maxLength = max(maxLength, right - left + 1);
            
            // Move to the next element
            right++;
        }
        
        return maxLength;
        
    }
};
