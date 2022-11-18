class Solution {
    public boolean valid(int[] piles , int h , int ph){
        for(int i = 0; i < piles.length ; i++){
            h -= (piles[i] + ph - 1) / ph;
            if(h < 0)
                return false;
        }
        return true;
    }
        public int minEatingSpeed(int[] piles, int h) {
        int left = 1;
        int right = 1000000000;
        
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(valid(piles, h, mid)) 
                right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }

}