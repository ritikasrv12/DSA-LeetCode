class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> cnt;
        for(int i : nums) ++cnt[i];
        int ans = nums[0];
        for(auto& p : cnt){
            if(p.second > cnt[ans]) ans = p.first;
        }
        return ans;
        
    }
};
