class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {

        string s,t;
        for(int i=0; i<word1.size(); i++){
            s+=word1[i];
        }


        for(int i=0; i<word2.size(); i++){
            t+=word2[i];
        }

        if(s==t){
            return 1;
        }
        return 0;
        
    }
};
