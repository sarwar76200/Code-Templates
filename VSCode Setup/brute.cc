#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.hh"
#else
#define dbg(x) ""
#endif

using namespace std;

const int MX_N = 3001;
string s1, s2;
int dp[MX_N][MX_N];

int lcs_iter(int l1, int l2) {
    for (int i = 0; i <= l1; ++i) {
        for (int j = 0; j <= l2; ++j) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
                continue;
            }
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[l1][l2];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s1 >> s2;
    lcs_iter(s1.length(), s2.length());
    int prv = -1;
    for (int i = 1; i <= s1.length(); ++i) {
        if (dp[i][s2.length()] > prv) {
            cout << s1[i - 1];
            prv = dp[i][s2.length()];
        }
    }


    return 0;
}