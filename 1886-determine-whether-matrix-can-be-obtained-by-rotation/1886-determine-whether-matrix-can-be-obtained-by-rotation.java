class Solution {
    int n ;
    private void rotate(int[][] mat){
        int[][] rotated = new int[n][n];
        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ; j < n ; j++){
                rotated[i][j] = mat[n-j-1][i];
            }
        }
        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ; j < n ; j++){
                mat[i][j] = rotated[i][j];
            }
        }
    }
    private boolean is_Equal(int[][] mat , int[][] target){
            for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(mat[i][j] != target[i][j])
                    return false;
            }
        }
        return true;
    }
    public boolean findRotation(int[][] mat, int[][] target) {
        this.n = mat.length;
        if(is_Equal(mat , target)){
            return true;
        }
        for(int i = 0 ; i < 3 ; i++){
            rotate(mat);
            if(is_Equal(mat , target)){
                return true;
            }    
        }
        return false;
    }
}