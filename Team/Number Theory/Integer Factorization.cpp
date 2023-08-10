vector<int64_t> factorization(int64_t n) {
    vector<int64_t> pf;
    while (n % 2 == 0) pf.push_back(2), n /= 2;

    for (int64_t i = 3; i * i <= n; i += 2)
        while (n % i == 0) pf.push_back(i), n /= i;

    if (n > 1) pf.push_back(n);
    return pf;
}