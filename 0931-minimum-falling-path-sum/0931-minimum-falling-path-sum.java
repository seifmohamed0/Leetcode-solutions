class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        int dp[][] = new int[n][m];
        for(int i = 0 ; i < m ; i++){
            dp[0][i] = matrix[0][i];
        }
        for(int i = 1 ; i < n ;i++){
            for(int j = 0 ; j < m ; j++){
                boolean flag = false;
                for(int k = -1 ; k <= 1 ; k++){
                    int n_i = i - 1 , n_j = j + k;
                    if(n_j < 0 || n_j == m)continue;
                    dp[i][j] = flag == false ? dp[n_i][n_j] + matrix[i][j] : Math.min(dp[i][j] , dp[n_i][n_j] + matrix[i][j]);
                    flag = true;
                }
            }
        }
        
        int ret = Integer.MAX_VALUE;
        for(int i = 0 ; i < m ; i++){
            ret = Math.min(ret , dp[n - 1][i]);
        }
        return ret;
    }
}