class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> a[1] == b[1] ? b[0] - a[0] : a[1] - b[1]);
        int ret = 0;
        int i = 0;
        int n = intervals.length;
        int left = intervals[0][0];
        int mn_right = intervals[0][1];
        while(i < n){
            while(i < n && intervals[i][0] == left){
                mn_right = Math.min(mn_right , intervals[i][1]);
                i++;
            }
            ++ret;
            while(i < n && intervals[i][0] < mn_right)
                ++i;
            if(i < n){
                left = intervals[i][0];
                mn_right = intervals[i][1];
            }
        }
        return n - ret;
    }
}