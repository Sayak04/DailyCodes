class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check the columns first
        for(int i = 0 ; i < 9; i++) {
            map<char, bool> mpp;
            for(int j = 0; j < 9; j++) {
                if(board[j][i] != '.') {
                    if(mpp.find(board[j][i]) == mpp.end())
                        mpp[board[j][i]] = true;
                    else return false;
                }
            }
            mpp.clear();
        }
        // check the rows second
        for(int i = 0; i < 9; i++) {
            map<char, bool> mpp;
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    if(mpp.find(board[i][j]) != mpp.end()) return false;
                    else mpp[board[i][j]] = true;
                }
            }
            mpp.clear();
        }
        
        // check the 3 * 3 squares
        for(int i = 0; i < 9; i += 3) {
            for(int j = 0; j < 9; j += 3) {
                
                map<char, bool> mpp;
                for(int row = 0; row < 3; row++) {
                    for(int col = 0; col < 3; col++) {
                        if(board[i+row][j+col] != '.') {
                            if(mpp.find(board[i+row][j+col]) != mpp.end()) return false;
                            else mpp[board[i+row][j+col]];
                        }
                    }
                } 
                mpp.clear();
            } 
        } 
        
        return true;
    }
};