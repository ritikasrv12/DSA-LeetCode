#define ll long long int
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll sum=0, cnt=0, baliKaBrakra = INT_MAX;
        for(auto el : nums){
            if((el^k) > el){
                sum += el^k;
                baliKaBrakra = min(baliKaBrakra,(ll)(el^k) - el);
                cnt++;
            }else{
                sum += el;
                baliKaBrakra = min(baliKaBrakra,(ll)el - (el^k));
            }
        }
        if(cnt%2 == 0) return sum;
        return sum - baliKaBrakra;
        
    }
};
