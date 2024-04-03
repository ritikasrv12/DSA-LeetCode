class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) return false;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (search(board, word, 0, i, j, visited))
                    return true;
            }
        }
        return false;
    }
    
    bool search(vector<vector<char>>& board, string& word, int index, int row, int col, vector<vector<bool>>& visited) {
        if (index == word.length()) return true;
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || visited[row][col] || board[row][col] != word[index])
            return false;
        
        visited[row][col] = true;
        bool found = search(board, word, index + 1, row - 1, col, visited) ||
                     search(board, word, index + 1, row + 1, col, visited) ||
                     search(board, word, index + 1, row, col - 1, visited) ||
                     search(board, word, index + 1, row, col + 1, visited);
        visited[row][col] = false;
        
        return found;
        
    }
};
