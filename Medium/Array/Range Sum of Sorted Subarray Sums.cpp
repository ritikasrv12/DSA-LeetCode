class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                pq.push(sum);
            }
        }
        int mod = 1e9 + 7;
        int sum = 0;
        for (int i = 1; i <= right; i++) {
            int val = pq.top();
            pq.pop();
            if (i >= left) {
                sum = (sum + val) % mod;
            }
        }
        return sum;
    }
};
