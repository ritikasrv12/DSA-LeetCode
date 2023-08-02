class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<std::vector<int>> result;
        permuteRecursive(nums, 0, result);
        return result;
    }

private:
    void permuteRecursive(std::vector<int>& nums, int start, std::vector<std::vector<int>>& result) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            std::swap(nums[start], nums[i]);
            permuteRecursive(nums, start + 1, result);
            std::swap(nums[start], nums[i]); // Backtrack
        }
        
    }
};
