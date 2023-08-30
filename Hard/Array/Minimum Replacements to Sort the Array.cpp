class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long res=0;
int n=nums.size();
long long maxMinVal=nums[n-1];
for(int i=n-2;i>=0;i--)
{
long long parts = ceil(nums[i]/(double)maxMinVal);
// no. of steps is parts-1
res+=(parts-1);
// the new maximized minimum value in a part
maxMinVal = nums[i]/parts;
}
return res;
        
    }
};
