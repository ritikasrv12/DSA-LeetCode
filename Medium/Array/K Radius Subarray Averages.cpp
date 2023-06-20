class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size(), len = 2 * k + 1;
        vector<int> ans(n, -1);
        if(n<len) return ans;
        vector<long long> prefix(n+1, 0);
        prefix[0] = 0;

        for(int i = 1; i<=nums.size(); i++){
            prefix[i] = prefix[i - 1] + nums[i-1];
        }
        for(int i = k; i+k<n; i++){
            ans[i] = (prefix[i + 1 + k] - prefix[i - k]) / (len);
        }
        return ans;
    }
};
