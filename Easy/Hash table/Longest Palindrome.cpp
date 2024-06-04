class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length(), ans=0;
        unordered_map<char, int> freq;
        for(auto c:s)freq[c]++;

        bool isOdd = false;
        for(auto [c, fr] : freq){
            if(fr%2==0) ans += fr;
            else{
                ans += fr -1;
                isOdd = true;
            }
        }
        return(isOdd) ? ans+1 : ans;
    }
};
