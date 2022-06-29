int mul_mod(int a, int b, int mod) {
    int x = 0, y = a % mod;
    while (b > 0) {
        if (b & 1) {
            x = (x + y) % mod;
        }
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod;
}