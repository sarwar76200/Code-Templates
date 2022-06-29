int64_t factorial_prime_power(int64_t n, int64_t p) {
    // number of times p occurs in n, O(nlgn)
    int64_t freq = 0;
    while (n > 0) {
        freq += n / p;
        n /= p;
    }
    return freq;
}