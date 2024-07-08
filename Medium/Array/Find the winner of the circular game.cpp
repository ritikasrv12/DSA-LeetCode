class Solution {
public:
    int findTheWinner(int n, int k) {
        std::vector<int> friends(n);
        for (int i = 0; i < n; ++i) {
            friends[i] = i + 1;
        }

        int index = 0; // Starting at the first friend
        
        // Continue until only one friend remains
        while (n > 1) {
            // Calculate the index of the friend to be removed
            index = (index + k - 1) % n;
            // Remove the friend
            friends.erase(friends.begin() + index);
            // Decrease the number of friends
            --n;
        }
        
        // The last remaining friend is the winner
        return friends[0];
        
    }
};
