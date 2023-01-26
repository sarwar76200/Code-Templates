const int N = 1005;
int arr[N + 1], dp[N + 1], dp_l[N + 1], dp_c[N + 1];

int numberOfLIS(int n) {
    if (n == 0) {
        return 0;
    }
    For(i, 0, n) {
        dp_c[i] = 1;
        dp_l[i] = 1;
    }
    For(i, 0, n) {
        For(j, 0, i) {
            if (arr[i] <= arr[j]) {
                continue;
            }
            if (dp_l[j] + 1 > dp_l[i]) {
                dp_l[i] = dp_l[j] + 1;
                dp_c[i] = dp_c[j];
            } else if (dp_l[j] + 1 == dp_l[i]) {
                dp_c[i] += dp_c[j];
            }
        }
    }
    int mx = 0;
    For(i, 0, n) {
        mx = max(mx, dp_l[i]);
    }
    int cnt = 0;
    For(i, 0, n) {
        if (dp_l[i] == mx) {
            cnt += dp_c[i];
        }
    }
    return cnt;
}