class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> result(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int sum = img[i][j];
                int count = 1;

                // Check and add values from surrounding cells
                if (i - 1 >= 0) {
                    sum += img[i - 1][j];
                    count++;
                    if (j - 1 >= 0) {
                        sum += img[i - 1][j - 1];
                        count++;
                    }
                    if (j + 1 < n) {
                        sum += img[i - 1][j + 1];
                        count++;
                    }
                }

                if (i + 1 < m) {
                    sum += img[i + 1][j];
                    count++;
                    if (j - 1 >= 0) {
                        sum += img[i + 1][j - 1];
                        count++;
                    }
                    if (j + 1 < n) {
                        sum += img[i + 1][j + 1];
                        count++;
                    }
                }

                if (j - 1 >= 0) {
                    sum += img[i][j - 1];
                    count++;
                }
                if (j + 1 < n) {
                    sum += img[i][j + 1];
                    count++;
                }

                result[i][j] = sum / count;
            }
        }

        return result;
        
    }
};
