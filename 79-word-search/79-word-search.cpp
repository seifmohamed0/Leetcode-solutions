class Solution {
public:
    int xd[4] = {0 , 0 , 1 , -1};
    int yd[4] = {1 , -1 , 0 , 0};
    int n , m , sz;
    vector<vector<bool>>vis;
    bool valid(int x , int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    bool is_exist(vector<vector<char>>&board , string& word , int i , int j , int k){

        if(word[k] != board[i][j] || vis[i][j])
            return false;
        if(k == sz - 1)
            return true;
        vis[i][j] = true;
        bool ret = false;
        for(int p = 0; p < 4 ; p++){
            int n_i = i + xd[p];
            int n_j = j + yd[p];
            if(valid(n_i , n_j)){
                ret |= is_exist(board , word ,n_i , n_j , k + 1);
            }
        }
        vis[i][j] = false;
        return ret;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        sz = word.size();
        vis.resize(n , vector<bool>(m));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0; j < m ; j++){
                if(board[i][j] == word[0]){
                    if(is_exist(board , word , i , j , 0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};