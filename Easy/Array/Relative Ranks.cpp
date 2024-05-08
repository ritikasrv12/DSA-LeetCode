class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string>rewards;
        int arr[score.size()];
        for(int i=0; i<score.size(); i++){
            arr[i]=0;
        }
        int turn=1;
        for(int i=0; i<score.size(); i++){
            int ind=std::max_element(score.begin(), score.end())-score.begin();
            arr[ind]=turn;
            score[ind]=-1;
            turn++;
        }
        for(int i=0; i<score.size(); i++){
            if(arr[i]==1){
                rewards.push_back("Gold Medal");
            }
            else if(arr[i]==2){
                rewards.push_back("Silver Medal");
            }
            else if(arr[i]==3){
                rewards.push_back("Bronze Medal");
        }
        else{
            rewards.push_back(to_string(arr[i]));
        }
        
    }
    return rewards;
    }
};
