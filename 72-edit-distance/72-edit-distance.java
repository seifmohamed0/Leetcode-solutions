class Solution {
    int[][] mem = new int [501][501];
    int n , m;
    String s1 , s2;
    public int solve(int idx1 , int idx2){
        if(idx1 == n || idx2 == m){
            return (n - idx1) + (m - idx2);
        }
        if(mem[idx1][idx2] != -1)
            return mem[idx1][idx2];
        
        int ret = 1000;
        if(s1.charAt(idx1) == s2.charAt(idx2)){
            ret = solve(idx1 + 1 , idx2 + 1);
        }
        ret = Math.min(ret , solve(idx1 , idx2 + 1) + 1);
        ret = Math.min(ret , solve(idx1 + 1 , idx2) + 1);
        ret = Math.min(ret , solve(idx1 + 1 , idx2 + 1) + 1);
        return mem[idx1][idx2] = ret;
    }
    public int minDistance(String word1, String word2) {
        n = word1.length();
        m = word2.length();
        s1 = word1 ;
        s2 = word2;
        for(int i = 0;  i < n ; i++)
             for(int j = 0; j < m ; j++)
                 mem[i][j] = -1;
        return solve(0 , 0);
    }
}