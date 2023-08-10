int64_t nCr(int n, int r) {
    int64_t N = 1, D = 1;
    r = min(r, n - r);
    if (r > 0) {
        while (r > 0) {
            N *= n, D *= r;
            int64_t g = __gcd(N, D);
            N /= g, D /= g;
            --n, --r;
        }
    }
    return N;
}