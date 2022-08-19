#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.hh"
#else
#define dbg(x) ""
#endif

using namespace std;

const int dx[] = {-1, +1, +0, +0, -1, -1, +1, +1};
const int dy[] = {+0, +0, -1, +1, -1, +1, -1, +1};

const int N = 501;
int mat[N][N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        int n, m;
        cin >> n >> m;

        vector<string> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                mat[i][j] = a[i][j] - '0';
            }
        }

        bool has_zero = false;
        bool only_one = false;

        auto valid = [&](int i, int j) {
            return i >= 0 && i < n && j >= 0 && j < m;
        };

        int ones = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ones += mat[i][j];
                has_zero |= !mat[i][j];
                for (int k = 0; k < 8; ++k) {
                    int p = i + dx[k];
                    int q = j + dy[k];
                    only_one |= valid(p, q) && mat[i][j] && !mat[p][q];
                }
            }
        }
        cout << ones - !has_zero - !only_one << '\n';
    }


    return 0;
}