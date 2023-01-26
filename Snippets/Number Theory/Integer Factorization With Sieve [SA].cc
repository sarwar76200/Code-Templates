const int MX_N = 1e6;
int PF[MX_N + 1];

void sieve() {
    memset(PF, -1, sizeof PF);
    for (int i = 2; i <= MX_N; ++i) {
        if (PF[i] == -1) {
            for (int64_t j = 1LL * i * i; j <= MX_N; j += i) PF[j] = i;
            PF[i] = i;
        }
    }
}

vector<int> factorize(int n) {
    vector<int> pf;
    while (n != 1) {
        pf.push_back(PF[n]);
        n /= PF[n];
    }
    sort(pf.begin(), pf.end());
    return pf;
}