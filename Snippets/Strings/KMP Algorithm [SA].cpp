vector<int> get_lps(const string& p) {
    int n = p.length();
    vector<int> lps(n);

    for (int i = 1, j = 0; i < n;) {
        if (p[i] == p[j]) {
            lps[i] = j + 1;
            ++j, ++i;
        }
        else if (j != 0) {
            j = lps[j - 1];
        }
        else {
            lps[i] = j, ++i;
        }
    }
    return lps;
}
vector<int> kmp(string s, string p) {
    vector<int> lps = get_lps(p), res;
    int n = s.length();
    int m = p.length();

    for (int i = 0, j = 0; i < n;) {
        if (s[i] == p[j]) {
            ++i, ++j;
        }
        else if (j != 0) {
            j = lps[j - 1];
        }
        else {
            ++i;
        }
        if (j == m) {
            res.push_back(i - m);
            j = lps[j - 1];
        }
    }
    return res;
}