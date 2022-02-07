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

int64_t invModF(int64_t a, int64_t m) {
    // Modular multiplicative inverse using fermat's little theorem
    // m is a prime number
    return bin_expo(a, m - 2, m);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int M = 97;
    int64_t inv = invModF(14, M);

    return 0;
}