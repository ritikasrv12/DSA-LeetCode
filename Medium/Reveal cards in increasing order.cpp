class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end()); // Sort the deck in increasing order
        deque<int> indices;
        vector<int> result(deck.size());

        // Initialize the deque with indices
        for (int i = 0; i < deck.size(); ++i) {
            indices.push_back(i);
        }

        // Reveal the cards
        for (int card : deck) {
            result[indices.front()] = card;
            indices.pop_front();
            if (!indices.empty()) {
                indices.push_back(indices.front());
                indices.pop_front();
            }
        }

        return result;
        
    }
};
