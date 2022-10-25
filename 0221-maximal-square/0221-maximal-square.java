class Solution {
    int[][] frq;
    int n, m;
    public boolean valid(int sz){
        for(int i = sz ; i <= n ; i++){
            for(int j = sz ; j <= m ; j++){
                int cnt = frq[i][j] - frq[i - sz][j] - frq[i][j - sz] + frq[i - sz][j - sz];
                if(cnt == sz * sz)
                    return true;
            }
        }
        return false;
    }
    public int maximalSquare(char[][] matrix) {
        n = matrix.length;
        m = matrix[0].length;
        frq = new int[n + 1][m + 1];
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                frq[i][j] = matrix[i - 1][j - 1] - '0';
                frq[i][j] += frq[i - 1][j] + frq[i][j - 1] - frq[i - 1][j - 1];
            }
        }
        int l = 1 , r = Math.min(n , m) , mid , ret = 0;
        while(r >= l){
            mid = (l + r) / 2;
            if(valid(mid)){
                ret = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return ret * ret;
    }
}