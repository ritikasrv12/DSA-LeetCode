class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int result=0;
        int i=0;
        int j=0;
        while(i<g.size() and j<s.size()){
            if(g[i]<=s[j]){
                result++;
                i++;
                j++;
            }
            else if(g[i]>s[j]){
                j++;
            }
        }
        return result;
        
    }
};
