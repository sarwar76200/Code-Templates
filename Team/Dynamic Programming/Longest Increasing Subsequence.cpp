const int MX_N = 1005;
int dp[MX_N];

int LIS(const vector<int>& a, int n, int i) {
    if (dp[i] != -1) return dp[i];

    int ans = 0;
    for (int j = i + 1; j < n; ++j) {
        if (a[j] > a[i]) {
            ans = max(ans, LIS(a, n, j));
        }
    }
    return dp[i] = 1 + ans;
}

int LIS(const vector<int>& a, int n) {
    int ans = 0;
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; ++i) {
        ans = max(ans, LIS(a, n, i));
    }
    return ans;
}