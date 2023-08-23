class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>count(26);        
        for (auto ch:s) 
            count[ch]++;

        vector<pair<int,char>>arr;
        for (auto ch: s)
            arr.push_back({count[ch], ch});
        sort(arr.rbegin(), arr.rend());

        string ret(s.size(),' ');

        int i = 0;
        for (auto [cnt, ch]: arr)
        {
            ret[i] = ch;
            if (i>=1 && ret[i]==ret[i-1])
                return "";
            i+=2;
            if (i>=s.size())
                i = 1;            
        }

        return ret;
        
    }
};
