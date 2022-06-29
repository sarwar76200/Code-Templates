const int MX_N = 1e8;
bitset<MX_N + 1> isPrime;

void sieve() {
    // false = prime, true = not prime
    isPrime[0] = isPrime[1] = true;
    for (int i = 4; i <= MX_N; i += 2) isPrime[i] = true;

    for (int64_t i = 3; i * i <= MX_N; i += 2) {
        if (!isPrime[i]) {
            for (int64_t j = i * i; j <= MX_N; j += i + i) isPrime[j] = true;
        }
    }
}