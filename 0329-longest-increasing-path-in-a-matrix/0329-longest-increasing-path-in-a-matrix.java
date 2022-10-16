class Solution {
    int[][] matrix;
    int[][] mem;
    int n , m;
    int[] xd = {0 , 0 , 1 , -1};
    int[] yd = {1 , -1 , 0 , 0};
    public boolean valid(int i , int j){
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    public int dfs(int i , int j){
        if(mem[i][j] != 0)
            return mem[i][j];
        int ret = 1;
        for(int k = 0; k < 4 ; k++){
            int n_i = i + xd[k] , n_j = j + yd[k];
            if(valid(n_i , n_j) && matrix[n_i][n_j] > matrix[i][j]){
                ret = Math.max(ret , dfs(n_i , n_j) + 1);
            }
        }
        return mem[i][j] = ret;
    }
    public int longestIncreasingPath(int[][] matrix) {
        this.matrix = matrix;
        n = matrix.length;
        m = matrix[0].length;
        mem = new int[n][m];
        int ret = 0;
        for(int i = 0; i < n ; i++){
            for(int j = 0; j< m; j++){
                ret = Math.max(ret , dfs(i , j));
            }
        }
        return ret;
    }
}