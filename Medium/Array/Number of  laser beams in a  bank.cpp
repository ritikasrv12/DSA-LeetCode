class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        if (bank.size() == 1) return 0;

        vector<int> numberOfLasers(bank.size(), 0);

        for (int i=0; i< bank.size(); i++){
            string curr = bank[i];
            for (int j=0; j< curr.size(); j++){
                if (curr[j] == '1'){
                    numberOfLasers[i]++;
                }
            }
        }

        int totalBeams = 0;

        for (int i=1; i< bank.size(); i++){
            int j = i -1;
            while (j >= 0  && numberOfLasers[j] == 0) j--;
            if (j == -1) continue;

            int prev = numberOfLasers[j];
            int curr = numberOfLasers[i];
            totalBeams  += prev * curr;
        }
        return totalBeams;
        
    }
};
