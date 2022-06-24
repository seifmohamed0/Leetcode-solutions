class Solution {
public:
    bool solve(vector<vector<char>>& board , int i , int j , bool row[9][10] , bool col[9][10] , bool group[9][10] ){
        if(i == 9)
            return true;
        if(j == 9)
            return solve(board , i + 1 , 0 , row , col , group);
        if(board[i][j] != '.'){
            return solve(board , i , j + 1 , row , col , group);
        }
        for(int val = 1 ; val <= 9 ; val++){
            if(row[i][val] && col[j][val] && group[((i / 3) * 3) + (j / 3)][val]){
                board[i][j] = (char)(val + '0');
                row[i][val] = col[j][val] = group[((i / 3) * 3) + (j / 3)][val] = false;
                if(solve(board , i , j + 1 , row , col , group))
                    return true;
                board[i][j] = '.';
                row[i][val] = col[j][val] = group[((i / 3) * 3) + (j / 3)][val] = true;
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        bool row[9][10] , col[9][10] , group[9][10];
        memset(row , 1 , sizeof(row));
        memset(col , 1 , sizeof(col));
        memset(group , 1 , sizeof(group));
        for(int i = 0; i < 9 ; i++){
            for(int j = 0 ; j < 9 ; j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '0';
                    int g = ((i / 3) * 3) + (j / 3);
                    row[i][num] = col[j][num] = group[g][num] = false;
                }
            }
        }
        solve(board , 0 , 0 , row , col , group);      
    }
};