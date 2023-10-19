class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        int i = convert(s);
        int j = convert(t);
        return s.substr(0,i)==t.substr(0,j);
    }

    int convert(string& str)
    {
        int i=0;
        for (int j=0; j<str.size(); j++)
        {
            if (str[j]!='#')
            {
                str[i] = str[j];
                i++;
            }
            else
            {
                i = max(0, i-1);
            }                
        }
        return i;
        
    }
};
