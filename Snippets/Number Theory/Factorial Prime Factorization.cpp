void factorize_factorial(int n) {
    // sieve size must be as large as n
	// prime factorization of n!, O(sqrt n)
    for (int i = 0; i < primes.size() && primes[i] <= n; i++) {
        int x = n, freq = 0;

        while (x / primes[i]) {
            freq += x / primes[i];
            x /= primes[i];
        }
        cout << primes[i] << "^" << freq << '\n';
    }
}