class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int start = 0, end = n - 1;
        while (start < n - 1 && arr[start] <= arr[start + 1]) {
            start++;
        }
        if (start == n - 1) {
            return 0;
        }
        while (end > 0 && arr[end - 1] <= arr[end]) {
            end--;
        }
        int res = min(n - start - 1, end);
        int i = 0, j = end;
        while (i <= start && j < n) {
            if (arr[i] <= arr[j]) {
                res = min(res, j - i - 1);
                i++;
            } else {
                j++;
            }
        }
        return res;

    }
};
