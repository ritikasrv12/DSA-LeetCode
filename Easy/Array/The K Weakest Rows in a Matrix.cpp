class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        // Create a priority queue of pairs, where the first element of the pair is the number of soldiers
        // in the row and the second element is the index of the row.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Iterate through each row in the matrix and count the number of soldiers.
        for (int i = 0; i < mat.size(); i++) {
            int soldiers = 0;
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 1) {
                    soldiers++;
                }
            }
            // Add the pair to the priority queue.
            pq.push(make_pair(soldiers, i));
        }
        
        // Create a vector to store the k weakest rows.
        vector<int> weakest;
        for (int i = 0; i < k; i++) {
            // Get the top element from the priority queue and add its index to the weakest vector.
            weakest.push_back(pq.top().second);
            pq.pop();
        }
        
        return weakest;

        
    }
};
