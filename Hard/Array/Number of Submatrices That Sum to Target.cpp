class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int result = 0;

        // Compute the prefix sum matrix
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                matrix[i][j] += matrix[i][j - 1];
            }
        }

        // Iterate over all possible pairs of columns
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                unordered_map<int, int> prefixSumCount;
                prefixSumCount[0] = 1;
                int currentSum = 0;

                // Iterate over all rows to compute the submatrix sum
                for (int k = 0; k < m; ++k) {
                    int colSum = matrix[k][j] - (i > 0 ? matrix[k][i - 1] : 0);
                    currentSum += colSum;

                    // Check if there is a submatrix with the target sum
                    if (prefixSumCount.find(currentSum - target) != prefixSumCount.end()) {
                        result += prefixSumCount[currentSum - target];
                    }

                    // Update the prefix sum count
                    prefixSumCount[currentSum]++;
                }
            }
        }

        return result;
        
    }
};
