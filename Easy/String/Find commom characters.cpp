class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> finalFreq(26, words.size());

        for(int i=0; i<words.size(); i++){
            vector<int> curFreq(26, 0);
            for(auto c: words[i]) curFreq[c-'a']++;

            for(char c='a'; c<='z'; c++)
            finalFreq[c-'a'] = min(finalFreq[c-'a'], curFreq[c-'a']);
        }
        vector<string> ans;
        for(char c='a'; c<='z'; c++){
            while(finalFreq[c-'a']--)
            ans.push_back(string(1, c));
        } 
        return ans;
    }
};
