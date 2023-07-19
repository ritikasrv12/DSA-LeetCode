class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<int> prev=intervals[0];
        int num=-1;
        for(vector<int>& A: intervals){
            if (A[0]<prev[1] && A[1]<=prev[1]){
                num++;
                prev=A;
            }
            else if(A[0]<prev[1] && A[1]>prev[1])
                num++;
            else 
                prev=A;
        }
        return num;     
        
    }
};
