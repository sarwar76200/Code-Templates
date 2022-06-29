struct Hasher {
    int n = 0;
    int64_t base[2] = {43, 59};
    int64_t mod[2] = {1000000007, 1000000033};
    std::string s;
    std::vector<int64_t> f_hash[2], r_hash[2];
    std::vector<int64_t> expo[2];

    Hasher(std::string s) {
        Hasher::init(s);
    }

    Hasher(std::string s, initializer_list<int64_t> base, initializer_list<int64_t> mod) {
        for (auto i : {0, 1}) {
            Hasher::base[i] = *(base.begin() + i);
            Hasher::mod[i] = *(mod.begin() + i);
        }
        Hasher::init(s);
    }

    void init(std::string s) {
        Hasher::s = s;
        Hasher::n = s.length();
        for (auto i : {0, 1}) {
            Hasher::f_hash[i].resize(n, 0);
            Hasher::r_hash[i].resize(n, 0);
            Hasher::expo[i].resize(n + 1, 1);
        }
        Hasher::compute_hash();
    }

    void compute_hash() {
        int64_t fh[2] = {0, 0}, rh[2] = {0, 0};
        for (int i = 0; i < Hasher::n; ++i) {
            for (auto j : {0, 1}) {
                fh[j] = (fh[j] * base[j] + s[i]) % mod[j];
                rh[j] = (rh[j] * base[j] + s[Hasher::n - i - 1]) % mod[j];
                Hasher::f_hash[j][i] = fh[j];
                Hasher::r_hash[j][i] = rh[j];
            }
        }
        for (int i = 1; i <= Hasher::n; ++i) {
            for (auto j : {0, 1})
                expo[j][i] = (expo[j][i - 1] * base[j]) % mod[j];
        }
    }

    uint64_t get_f_hash(int l, int r) {
        int64_t h[2] = {0, 0};
        for (auto i : {0, 1}) {
            h[i] = (f_hash[i][r] - (l > 0 ? f_hash[i][l - 1] * expo[i][r - l + 1] : 0)) % mod[i];
            h[i] < 0 ? h[i] += mod[i] : h[i];
        }
        return (h[0] << 32) ^ h[1];
    }

    uint64_t get_r_hash(int l, int r) {
        int64_t h[2] = {0, 0};
        for (auto i : {0, 1}) {
            h[i] = (r_hash[i][r] - (l > 0 ? r_hash[i][l - 1] * expo[i][r - l + 1] : 0)) % mod[i];
            h[i] < 0 ? h[i] += mod[i] : h[i];
        }
        return (h[0] << 32) ^ h[1];
    }

    int length() {
        return Hasher::n;
    }
};