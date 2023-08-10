const int base = 347, mod = 1000000007;

int get_hash(const string& s, int m) {
    int hash = 0, exp = 1;
    for (int i = m - 1; i >= 0; --i) {
        hash = (hash % mod + (s[i] * exp) % mod) % mod;
        exp = (exp * base) % mod;
    }
    return hash;
}
vector<int> rabin_karp(const string& s, const string& p) {
    vector<int> pos;
    int n = s.length(), m = p.length();
    if (n < m || m == 0 || n == 0)
        return pos;

    int exp = 1;
    for (int i = 1; i <= m - 1; ++i) {
        exp = (exp * base) % mod;
    }
	
    int h_txt = get_hash(s, m);
    int h_pat = get_hash(p, m);
	
    if (h_txt == h_pat) {
        pos.push_back(0);
    }
    for (int i = m; i < n; ++i) {
        h_txt = (h_txt - (exp * s[i - m]) % mod) % mod;
        h_txt = (h_txt + mod) % mod;
        h_txt = (h_txt * base) % mod;
        h_txt = (h_txt + s[i]) % mod;

        if (h_txt == h_pat) {
            pos.push_back(i - m + 1);
        }
    }
    return pos;
}