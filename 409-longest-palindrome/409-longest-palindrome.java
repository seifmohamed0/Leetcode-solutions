class Solution {
    public int longestPalindrome(String s) {
        int[] frq = new int[128];
        for(int i = 0 ; i < s.length() ; i++){
            frq[s.charAt(i)]++;
        }
        Boolean done = false;
        int ret = 0;
        for(int i = 0 ; i < 128 ; i++){
            ret += frq[i]/2;
            if((frq[i] & 1) == 1)done = true;
        }
        return 2*ret + (done == true ? 1 : 0);
    }
}