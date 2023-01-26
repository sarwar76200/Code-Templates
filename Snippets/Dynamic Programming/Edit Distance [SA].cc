const int N = 2005, INF = 1E6;
int dp[N][N];

int ed(string& s, string& t, int n, int m) {
    if (n == 0) return m;
    if (m == 0) return n;

    int& ans = dp[n][m];
    if (ans != -1) return ans;

    ans = INF;

    if (s[n - 1] == t[m - 1]) {
        ans = ed(s, t, n - 1, m - 1);
    }

    ans = min(ans, 1 + min({ed(s, t, n - 1, m),
                            ed(s, t, n, m - 1),
                            ed(s, t, n - 1, m - 1)}));
    return ans;
}