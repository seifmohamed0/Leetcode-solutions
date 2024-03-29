class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int ret = A[A.size() - 1] - A[0];
        int left = A[0] + K, right = A[A.size() - 1] - K;
        for (int i = 0; i < A.size() - 1; i++) {
            int a = max(A[i] + K, right), b = min(left, A[i + 1] - K);
            ret = min(ret, a - b);
        }
        return ret;
    }
};