class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char task : tasks)
            freq[task]++;
        
        priority_queue<int> pq;
        for (auto& kv : freq)
            pq.push(kv.second);
        
        int intervals = 0;
        while (!pq.empty()) {
            vector<int> temp;
            int i = 0;
            while (i <= n) {
                if (!pq.empty()) {
                    if (pq.top() > 1)
                        temp.push_back(pq.top() - 1);
                    pq.pop();
                }
                intervals++;
                if (pq.empty() && temp.empty())
                    break;
                i++;
            }
            for (int t : temp)
                pq.push(t);
        }
        
        return intervals;
        
    }
};
