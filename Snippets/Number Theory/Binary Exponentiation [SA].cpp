int bin_expo(int b, int e, int m) {
    b %= m;
    int res = 1;
    while (e > 0) {
        if (e & 1) res = b * res % m;
        b = b * b % m;
        e >>= 1;
    }
    return res;
}