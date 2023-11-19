class Solution {
public:
    int reductionOperations(vector<int>& nums) {
       map<int, int>mp;
       set<int>s;
       for (int i = 0; i < nums.size(); i++) {
           mp[nums[i]]++;
           s.insert(nums[i]);
       }

       int k=0;
       int ans=0;

       for(auto i:s){
           ans+=k*mp[i];
           k++;
       }
       return ans;

            
    }
};
