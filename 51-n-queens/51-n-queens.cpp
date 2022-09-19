class Solution {
public:
    bool row[10] , col[10] , cor1[20] ,cor2[20];
    vector<string>s;
    void solve(int x , int y , int n , vector<vector<string>>&ret){
        if(x == n){
           bool flag = true;
            for(int i=  0 ; i < n ; i++)
                if(!row[i] || (!col[i]))
                    flag = false;
         if(flag)
           ret.push_back(s);
         return;
        }
        if(y == n){
            return void(solve(x + 1 , 0 , n , ret));
        }
        if(!row[x] && (!col[y]) && (!cor1[x + y]) && (!cor2[x - y + 10])){
            s[x][y] = 'Q';
            row[x] = true;
            col[y] = true;
            cor1[x + y] = true;
            cor2[x - y + 10] = true;
            solve(x , y + 1 , n , ret);
            s[x][y] = '.';
            row[x] = false;
            col[y] = false;
            cor1[x + y] = false;
            cor2[x - y + 10] = false;
        }
        solve(x , y + 1 , n , ret);
        return ;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ret;
        for(int i = 0 ;i < n ; i++){
            string s2 = "";
            for(int j = 0 ; j < n ; j++){
                s2 += '.';
           }
            s.push_back(s2);
        }
        solve(0 , 0 , n , ret);   
        return ret;
    }
};