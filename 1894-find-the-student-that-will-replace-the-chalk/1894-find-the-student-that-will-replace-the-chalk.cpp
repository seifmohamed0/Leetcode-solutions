class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        if(k < chalk[0])
            return 0;
        int n = chalk.size();
        for(int i = 1 ; i < n ; i++){
            chalk[i] += chalk[i - 1];
            if(chalk[i] > k)
                return i;
        }
        int times = k / chalk[n - 1];
        k -= times * chalk[n - 1];
        return upper_bound(chalk.begin() , chalk.end() , k) - chalk.begin();
    }
};