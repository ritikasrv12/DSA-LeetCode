class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int paper = 0, glass = 0, metal = 0, time = 0;
        for(int i=0; i<garbage.size(); i++){
            for(char c: garbage[i]){
                if(c == 'P') paper = i;
                else if(c == 'G') glass = i;
                else if(c == 'M') metal = i;
                time++;

            }
        }
        for(int i = 1; i<travel.size(); i++){
            travel[i] += travel[i-1];
        }
        time += paper == 0 ? 0 : travel[paper - 1];
        time += glass == 0 ? 0 : travel[glass - 1];
        time += metal == 0 ? 0 : travel[metal - 1];

        return time;
        
    }
};
