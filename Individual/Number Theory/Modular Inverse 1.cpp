int inv(int a, int m) {
    // m is a prime number
    return bin_expo(a, m - 2, m);
}