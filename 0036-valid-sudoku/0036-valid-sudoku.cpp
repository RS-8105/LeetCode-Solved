class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i = 0; i<9; i++){
            vector<int> row(9,0);
            for(int j = 0; j<9; j++){
                if(board[i][j] == '.')continue;
                row[board[i][j] - '1']++;
                if(row[board[i][j] - '1'] > 1)return false;
            }
        }
        for(int i = 0; i<9; i++){
            vector<int> cols(9,0);
            for(int j = 0; j<9; j++){
                if(board[j][i] == '.')continue;
                cols[board[j][i] - '1']++;
                if(cols[board[j][i] - '1'] > 1)return false;
            }
        }

        for (int square = 0; square < 9; square++) {
            vector<int> sq(9,0);
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int row = (square / 3) * 3 + i;
                    int col = (square % 3) * 3 + j;
                    if (board[row][col] == '.') continue;
                    sq[board[row][col] - '1']++;
                    if (sq[board[row][col] - '1'] > 1) return false;
                }
            }
        }
        return true;
    }
};