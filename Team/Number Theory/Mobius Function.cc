/*
mu[n] = { 0, if n has one or more repeated prime factors
	      1, if n = 1
	 (-1)^k, if n is a product of k distinct primes
*/

const int MX_N = 1e6;
int spf[MX_N + 1];
int mu[MX_N + 1];

void mobius() {
  memset(spf, -1, sizeof spf);
  for (int i = 2; i <= MX_N; ++i) {
    if (spf[i] == -1) {
      for (int64_t j = 1LL * i * i; j <= MX_N; j += i) spf[j] = i;
      spf[i] = i;
    }
  }
  mu[1] = 1;
  for (int i = 2; i <= MX_N; ++i) {
    vector<int> pf;
    int n = i;
    while (n != 1) {
      pf.push_back(spf[n]);
      n /= spf[n];
    }
    int k = (int) pf.size();
    sort(pf.begin(), pf.end());
    pf.erase(unique(pf.begin(), pf.end()), pf.end());
    if (k != (int) pf.size()) {
      mu[i] = 0;
      continue;
    }
    mu[i] = (k & 1) ? -1 : 1;
  }
}
