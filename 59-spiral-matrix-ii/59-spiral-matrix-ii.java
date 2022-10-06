class Solution {
    // right down left up
    
    public int[][] generateMatrix(int n) {
        int[][] ret = new int[n][n];
        int curr = 2;
        int ptr = 0;
        int i = 0 , j = 0;
        ret[0][0] = 1;        
        int[] xd = {0 , 1 , 0 , -1};
        int[] yd = {1 , 0 , -1 , 0};
        while(curr <= n * n){
            int n_i = i + xd[ptr];
            int n_j = j + yd[ptr];
            while(n_i == n || n_j == n || n_i == -1 || n_j == -1 || ret[n_i][n_j] != 0){
                ptr = (ptr + 1) % 4 ;
                n_i = i + xd[ptr];
                n_j = j + yd[ptr];
            }
            ret[n_i][n_j] = curr++;
            i = n_i;
            j = n_j;
        }
        return ret;
    }
}