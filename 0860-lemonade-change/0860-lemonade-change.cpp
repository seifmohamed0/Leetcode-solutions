class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0 , tens = 0;
        for(auto it : bills){
            if(it == 5){
                ++fives;
            }else if(it == 10){
                if(!fives)
                    return false;
                --fives ;
                ++tens;
            }else{
                if(tens && fives){
                    --tens;
                    --fives;
                }else if(fives > 2){
                    fives -= 3;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};