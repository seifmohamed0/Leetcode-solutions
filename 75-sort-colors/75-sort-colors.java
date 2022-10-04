class Solution {
    public void sortColors(int[] nums) {
        int[] col = new int[3];
        for(int i = 0 ; i < nums.length ; i++){
            col[nums[i]]++;
        }
        for(int i = 0 ; i < nums.length ; i++){
            for(int j = 0; j < 3 ; j++)
                if(col[j] > 0){
                    --col[j];
                    nums[i] = j;
                    break;
                }
        }
        return;
    }
    
}