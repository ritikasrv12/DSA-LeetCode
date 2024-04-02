class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;

        unordered_map<char, char> s_to_t_map;
        unordered_map<char, char> t_to_s_map;

        for (int i = 0; i < s.size(); ++i) {
            if (s_to_t_map.find(s[i]) != s_to_t_map.end()) {
                if (s_to_t_map[s[i]] != t[i])
                    return false;
            } else {
                s_to_t_map[s[i]] = t[i];
            }

            if (t_to_s_map.find(t[i]) != t_to_s_map.end()) {
                if (t_to_s_map[t[i]] != s[i])
                    return false;
            } else {
                t_to_s_map[t[i]] = s[i];
            }
        }

        return true;
        
    }
};
