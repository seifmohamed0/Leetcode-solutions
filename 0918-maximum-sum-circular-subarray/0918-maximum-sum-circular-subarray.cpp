class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int sum = 0, mn = INT_MAX, mx = INT_MIN, curMax = 0, curMin = 0;
		for (int num : A) {
			curMin = min(curMin + num, num);
            mn = min(mn, curMin);
            curMax = max(curMax + num, num);
            mx = max(mx, curMax);
            sum += num;
		}
        return (sum - mn == 0) ? mx : max(mx, sum - mn);
    }
};