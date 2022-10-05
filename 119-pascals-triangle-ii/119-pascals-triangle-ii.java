class Solution {
    public List<Integer> getRow(int rowIndex) {
        Integer[] lis = new Integer[1];
        lis[0] = 1 ;
        int row = 0;
        while(row < rowIndex){
            ++row;
            int sz = row;
            Integer[] lis2 = new Integer[sz + 1];
            lis2[0] = lis2[sz] = 1;
            for(int i = 1; i < sz ; i++){
                lis2[i] = lis[i - 1] + lis[i];
            }
            lis = lis2;
        }
        List<Integer> ret = Arrays.asList(lis);
        return ret;
    }
}