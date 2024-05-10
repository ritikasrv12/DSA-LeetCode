class Solution {
public:
vector<int> countOfSmallerOrEqualElements(vector<int>& arr, double val){
    int n = arr.size() , count = 0, ansi, ansj, i=0, j=1;
    double maxRatio = 0.0;

    while(i < n-1){
        while(j<n && arr[i] > val * arr[j]){
            j++;
        }
        count += (n-j);
        if(j == n)break;

        double curRatio = (arr[i] * 1.0)/arr[j];
        if(maxRatio < curRatio){
            maxRatio = curRatio;
            ansi = i;
            ansj = j;
        }
        i++;
    }
    return {count, ansi, ansj};
}
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size(), ansi, ansj;
        double l=0.0, r=1.0;

        while(l<r){
            double mid = (l+r)/2;
            vector<int> count = countOfSmallerOrEqualElements(arr, mid);

            if(count[0] == k){
                ansi = count[1], ansj = count[2];
                break;
            }else if(count[0] > k){
                r = mid;
            }else l = mid;
        }
        return {arr[ansi], arr[ansj]}; 
        
    }
};
