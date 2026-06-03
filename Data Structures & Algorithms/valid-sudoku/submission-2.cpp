class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
//1.check Each row must contain the digits 1-9 without duplicates.
        for(vector<char>& row : board){
            unordered_set<char> s;
            for(int i=0;i<9;i++){
                int val=row[i];
                if(val=='.') continue;
               

                if(s.count(val)) return false;
                s.insert(val);
            }
        }

//2.Each column must contain the digits 1-9 without duplicates.
//row==column==board.size()==9
        for (int col = 0; col < 9; col++) { // each column
            unordered_set<char> s;
            for (int row = 0; row < 9; row++) {// each element in that column
                char val = board[row][col];
                if(val=='.') continue;
                
                if(s.count(val)) return false;
                s.insert(val);
            }
        }

/* 3.Each of the nine 3 x 3 sub-boxes of the grid must contain 
the digits 1-9 without duplicates.*/
        for (int square = 0; square < 9; square++) {
            unordered_set<char> s;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int row = (square / 3) * 3 + i;
                    int col = (square % 3) * 3 + j;

                    char val = board[row][col];
                    if(val=='.') continue;
                    
                    
                    if (s.count(val)) return false;
                    s.insert(val);
                }
            }
        }
        return true;
        
    }
};
/*LeetCode / standard Sudoku boards: ✅ Range check not needed
  User input / custom board: ✅ Range check recommended
  ### if (val < '1' || val > '9') return false; =>after skip-'.'
*/