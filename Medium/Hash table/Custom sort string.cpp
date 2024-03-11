class Solution {
public:
    string customSortString(string order, string s) {
        auto cmp = [&](char a, char b) {
            return order.find(a) < order.find(b);
        };
        
        // Sort s using the custom comparator
        sort(s.begin(), s.end(), cmp);
        
        return s;
        
    }
};
