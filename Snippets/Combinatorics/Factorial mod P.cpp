const int N = 100001;
long long fac[N];

int fact_mod(int n, int p) {
    fac[0] = 1;
    for (int i = 1; i < p; i++) {
        fac[i] = (fac[i - 1] * i) % p;
    }
    int res = 1;
    while (n > 1) {
        if ((n / p) % 2) {
            res = p - res;
        }
        res = (res * fac[n % p]) % p;
        n /= p;
    }
    return res;
}