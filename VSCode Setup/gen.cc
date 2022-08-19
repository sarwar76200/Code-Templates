#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.hh"
#else
#define dbg(x) ""
#endif

using namespace std;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 100000;

    cout << n << '\n';

    for (int i = 0; i < n; ++i) {
        cout << n - i << " ";
    }
    cout << '\n';


    return 0;
}