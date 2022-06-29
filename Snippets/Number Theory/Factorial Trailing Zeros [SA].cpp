int64_t fact_trailing_zeros(int64_t n) {
    int64_t count = 0;
    for (int64_t i = 5; i <= n; i *= 5)
        count += (n / i);
    return count;
}