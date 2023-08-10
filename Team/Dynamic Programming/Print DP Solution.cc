int go(int i, int j) {
    if (i == n || j == m) return 0;
    int& ans = dp[i][j];
    if (ans != -1) return ans;
    ans = 0;
    int c1 = 0;
    if (s[i] == t[j]) {
        c1 = 1 + go(i + 1, j + 1);
    }
    int c2 = 0 + go(i + 1, j);
    int c3 = 0 + go(i, j + 1);
    return ans = max({c1, c2, c3});
}
// max_length = go(0, 0)

void trace(int i, int j) {
    if (i == n || j == m) return;
    int ans = go(i, j);
    int c1 = 0;
    if (s[i] == t[j]) {
        c1 = 1 + go(i + 1, j + 1);
        if (c1 == ans) {
            cout << s[i];
            trace(i + 1, j + 1);
            return;
        }
    }
    int c2 = 0 + go(i + 1, j);
    if (c2 == ans) {
        trace(i + 1, j);
        return;
    }
    int c3 = 0 + go(i, j + 1);
    if (c3 == ans) {
        trace(i, j + 1);
        return;
    }
}
// call trace(0, 0)