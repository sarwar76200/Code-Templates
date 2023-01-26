const int N = 10001;
const int M[2] = {int(1E9 + 7), int(1E9 + 33)};
const int B[2]{47, 59};
int64_t fwd[2][N], rev[2][N];
int64_t expo[2][N + 1];
int n;

void compute_hash(string s) {
    n = (int) s.length();

    int fh[2] = {0, 0}, rh[2] = {0, 0};
    expo[0][0] = expo[1][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (const int& j : {0, 1}) {
            expo[j][i + 1] = int((1LL * expo[j][i] * B[j]) % M[j]);
            fh[j] = int((1LL * fh[j] * B[j] + s[i]) % M[j]);
            rh[j] = int((1LL * rh[j] * B[j] + s[n - i - 1]) % M[j]);
            fwd[j][i] = fh[j];
            rev[j][n - 1 - i] = rh[j];
        }
    }
}
uint64_t get_fwd_hash(int l, int r) {
    int h[2] = {0, 0};
    for (const int& i : {0, 1}) {
        h[i] = int((fwd[i][r] - (l > 0 ? 1LL * fwd[i][l - 1] * expo[i][r - l + 1] : 0)) % M[i]);
        if (h[i] < 0) h[i] += M[i];
    }
    return (uint64_t(h[0]) << 32) ^ uint64_t(h[1]);
}
uint64_t get_rev_hash(int l, int r) {
    int h[2] = {0, 0};
    for (const int& i : {0, 1}) {
        h[i] = int((rev[i][l] - (r < n - 1 ? 1LL * rev[i][r + 1] * expo[i][r - l + 1] : 0)) % M[i]);
        if (h[i] < 0) h[i] += M[i];
    }
    return (uint64_t(h[0]) << 32) ^ uint64_t(h[1]);
}