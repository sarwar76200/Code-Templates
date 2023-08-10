long long nCr(int n, int r) {
    long long N = 1, D = 1;
    r = min(r, n - r);
    if (r > 0) {
        while (r > 0) {
            N *= n, D *= r;
            long long g = __gcd(N, D);
            N /= g, D /= g;
            --n, --r;
        }
    }
    return N;
}