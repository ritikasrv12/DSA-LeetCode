class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long sum=0, j=0, count=0;
        for(int i=1; i<=k; i++){
            if(happiness[j]-count>=0){
                sum+=happiness[j];
                sum -=count;
                count++;
                j++;
            }
        }
        return sum;
        
    }
};
