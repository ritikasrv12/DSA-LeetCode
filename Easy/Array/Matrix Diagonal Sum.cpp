class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int s=0,i=0,j=0;
        while(i<mat.size())
        {
            s=s+mat[i][j];
            i++;
            j++;
        }
        j=mat.size()-1,i=0;
        while(i<mat.size())
        {
            if(i!=j)
                s=s+mat[i][j];
            i++;
            j--;
        }
        return s;

        
    }
};
