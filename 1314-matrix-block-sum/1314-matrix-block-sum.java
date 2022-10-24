class Solution {
    int[][] frq;
    int n , m;
    int solve(int i , int j , int k){
        int l_i = Math.max(0 , i - k) , l_j = Math.max(0 , j - k);
        int r_i = Math.min(n - 1 , i + k) , r_j = Math.min(m - 1 , j + k);
        int ret = frq[r_i][r_j];
        if(l_i > 0)
            ret -= frq[l_i - 1][r_j];
        if(l_j > 0)
            ret -= frq[r_i][l_j - 1];
        if(l_i > 0 && l_j > 0)
            ret += frq[l_i - 1][l_j - 1];
        return ret;
    }
    public int[][] matrixBlockSum(int[][] mat, int k) {
        n = mat.length;
        m = mat[0].length;
        frq = new int[n][m];
        for(int i = 0 ; i < n;  i++){
            for(int j = 0 ; j < m ; j++){
                frq[i][j] = mat[i][j];
                if(i > 0)
                    frq[i][j] += frq[i - 1][j];
                if(j > 0)
                    frq[i][j] += frq[i][j - 1];
                if(i > 0 && j > 0)
                    frq[i][j] -= frq[i - 1][j-1];
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                mat[i][j] = solve(i , j , k);
            }
        }
        return mat;
    }
}