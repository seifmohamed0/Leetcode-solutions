class Solution {
    public int lengthOfLastWord(String s) {
        int cnt = 0;
        boolean flag = false;
        for(int i = 0; i < s.length() ; i++){
            if(s.charAt(i) == ' '){
                flag = true;
            }else{
                if(flag){
                    cnt = 1;
                    flag = false;
                }else{
                    ++cnt;
                }
            }
        }
        return cnt;
    }
}