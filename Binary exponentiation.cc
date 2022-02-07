#include <bits/stdc++.h>

using namespace std;

int64_t bin_expo(int64_t b, int64_t e, int64_t m) {
    b %= m;
    int64_t res = 1;
    while (e > 0) {
        if (e & 1) res = b * res % m;
        b = b * b % m;
        e >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int M = 97;
    cout << bin_expo(7, 10087, M) << '\n';

    return 0;
}