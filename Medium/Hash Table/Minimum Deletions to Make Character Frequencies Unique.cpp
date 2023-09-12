class Solution {
public:
    int minDeletions(string s) {
        vector<int> frq(26,0);
        for(auto x: s){
            frq[x- 'a']++;
        }
        sort(frq.begin(), frq.end(), greater<int>());
        int max_frq = s.size();
        int min_del = 0;
        for(int i = 0; i<26 and frq[i] > 0; i++){
            if(frq[i] > max_frq){
                min_del += frq[i] - max_frq;
                frq[i] = max_frq;
            }
            max_frq = max(0,frq[i]-1);
        }
        return min_del;

        
    }
};
