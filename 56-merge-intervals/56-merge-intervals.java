class Solution {
    public int[][] merge(int[][] intervals) {
        int n = intervals.length;
        Arrays.sort(intervals , (a , b)->Integer.compare(a[0],b[0]));
        List<int[]> AL = new ArrayList<int[]>();
        int idx = 1 ;
        int[] curr = intervals[0];
        while(idx < n){
            if(intervals[idx][0] <= curr[1]){
                curr[1] = Math.max(intervals[idx][1] , curr[1]);
            }else{
                AL.add(curr);
                curr = intervals[idx];
            }
            ++idx;
        }
        AL.add(curr);
        int[][] ret = new int[AL.size()][2];
        for(int i = 0 ; i < AL.size() ; i++){
            ret[i][0] = AL.get(i)[0];
            ret[i][1] = AL.get(i)[1];
        }
        return ret;
    }
}