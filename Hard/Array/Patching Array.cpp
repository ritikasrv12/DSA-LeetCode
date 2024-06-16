class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long miss = 1;  // the smallest number that we cannot form
        int added = 0;  // number of patches added
        int i = 0;      // index for nums

        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) {
                // If the current number in nums can be used to form `miss`, use it
                miss += nums[i];
                i++;
            } else {
                // Otherwise, add `miss` to the array to extend the range
                miss += miss;
                added++;
            }
        }

        return added;
        
    }
};
