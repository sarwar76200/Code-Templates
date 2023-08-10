vector<bool> segmented_sieve(int64_t L, int64_t R) {
    int64_t LIMIT = 1 + sqrt(R);
    vector<bool> mark(LIMIT);
    vector<int64_t> primes;
    for (int64_t i = 2; i < LIMIT; ++i) {
        if (!mark[i]) {
            primes.push_back(i);
            for (int64_t j = i * i; j < LIMIT; j += i)
                mark[j] = true;
        }
    }
    vector<bool> is_prime(R - L + 1, true);
    for (auto& i : primes)
        for (int64_t j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            is_prime[j - L] = false;
    is_prime[0] = L != 1;
    return is_prime;
}