class Solution {
    public int maxScoreSightseeingPair(int[] values) {
        int n = values.length;
        int mx = values[0] ,  ret = 0;
        for(int i = 1 ; i < n ; i++){
            --mx;
            ret = Math.max(ret , mx + values[i]);
            mx = Math.max(mx , values[i]);
        }
        return ret;
    }
}