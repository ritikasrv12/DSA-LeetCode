class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
       int n = dist.size();
        vector<int> timeRequired(n);

        for (int i = 0; i < n; i++) {
            timeRequired[i] = (dist[i]+speed[i]-1) / speed[i];
        }

        sort(timeRequired.begin(), timeRequired.end());

        int count = 0;
         

        for (int i = 0; i <timeRequired.size(); i++) {
            if (timeRequired[i] > i)count++; 
            else break;
           
            }
        

        return count;
    }
};
