class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int moves = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= nums[i - 1]) {
                // Calculate the number of moves needed to make nums[i] unique
                int increment = nums[i - 1] - nums[i] + 1;
                // Increment the current element
                nums[i] += increment;
                // Accumulate the total number of moves
                moves += increment;
            }
        }

        return moves;
        
    }
};
