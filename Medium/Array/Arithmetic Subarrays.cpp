class Solution {
public:
bool checkArithmeticSequence(vector<int>& subarray) {
        sort(subarray.begin(), subarray.end());
        int commonDifference = subarray[1] - subarray[0];

        for (int i = 2; i < subarray.size(); ++i) {
            if (subarray[i] - subarray[i - 1] != commonDifference) {
                return false;
            }
        }

        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = l.size();
        vector<bool> result;

        for (int i = 0; i < m; ++i) {
            int left = l[i];
            int right = r[i];

            vector<int> subarray(nums.begin() + left, nums.begin() + right + 1);

            result.push_back(checkArithmeticSequence(subarray));
        }

        return result;
        
    }
};
