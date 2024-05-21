class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;  // This will store all the subsets
        vector<int> current;         // This will store the current subset being explored
        backtrack(nums, 0, current, result);
        return result;
    }

private:
    void backtrack(const vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result) {
        result.push_back(current);  // Add the current subset to the result

        for (int i = start; i < nums.size(); ++i) {
            current.push_back(nums[i]);  // Include nums[i] in the current subset
            backtrack(nums, i + 1, current, result);  // Explore further subsets
            current.pop_back();  // Exclude nums[i] from the current subset for backtracking
        }
        
    }
};
