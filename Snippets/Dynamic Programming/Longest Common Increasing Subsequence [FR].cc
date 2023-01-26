const int N = 1005;
int arr1[N + 1], arr2[N + 1];
int dp[N + 1];

int LCIS(int n, int m) {
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        int mx = 0;
        for (int j = 0; j < m; j++) {
            if (arr1[i] == arr2[j]) {
                dp[j] = max(dp[j], mx + 1);
            } else if (arr1[i] > arr2[j]) {
                mx = max(mx, dp[j]);
            }
        }
    }
    int res = 0;
    for (int i = 0; i < m; i++) {
        res = max(res, dp[i]);
    }
    return res;
}