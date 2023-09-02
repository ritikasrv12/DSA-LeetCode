class Solution {
public:
int dp[51];
    int find(int i,string s,map<char,vector<string>>&P){
        if(i<0)return 0;
        if(dp[i] != -1)return dp[i];
        
        int score = INT_MAX;
        for(auto&x:P[s[i]]){
            //now compare if string match here or not
            int sz = x.size();
            if((i+1)>=sz){
                int f = 0;
                for(int j=0;j<sz;++j){
                    if(s[i-j] != x[j]){
                        f=1;
                        break;
                    }
                }
                if(f == 0){
                    score = min(score,find((i-sz),s,P));
                }
            }
        }
        score = min(score,find(i-1,s,P)+1);
        return dp[i] = score;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        map<char,vector<string>>P;
        sort(dictionary.begin(),dictionary.end());
        for(auto&x:dictionary){
            P[x[0]].push_back(x);
        }
        memset(dp,-1,sizeof(dp));
        reverse(s.begin(),s.end());
        int n = s.size();
        
        return find(n-1,s,P);
        
    }
};
