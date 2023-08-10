const int N = 10001;
const int B = 47, M = 1E9 + 7;
int64_t fwd[N], rev[N];
int64_t expo[N + 1];
int n;

void compute_hash(string s) {
  n = (int) s.length();

  int64_t fh = 0, rh = 0;
  expo[0] = 1;
  for (int i = 0; i < n; ++i) {
    expo[i + 1] = (expo[i] * B) % M;
    fh = (fh * B + s[i]) % M;
    rh = (rh * B + s[n - i - 1]) % M;
    fwd[i] = fh;
    rev[n - 1 - i] = rh;
  }
}
int64_t get_fwd_hash(int l, int r) {
  int64_t h = 0;
  h = (fwd[r] - (l > 0 ? fwd[l - 1] * expo[r - l + 1] : 0)) % M;
  if (h < 0) h += M;
  return h;
}
int64_t get_rev_hash(int l, int r) {
  int64_t h = 0;
  h = (rev[l] - (r < n - 1 ? rev[r + 1] * expo[r - l + 1] : 0)) % M;
  if (h < 0) h += M;
  return h;
}