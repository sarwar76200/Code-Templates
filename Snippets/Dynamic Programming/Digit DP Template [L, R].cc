int count(const string& L, const string& R, int N, int i = 0, bool l = false, bool r = false) {
  if (i == N) {
    return 0;
  }
  int ans = 0;
  int st = l ? 0 : (L[i] - '0'), ed = r ? 9 : (R[i] - '0');
  for (int j = st; j <= ed; ++j) {
    ans += count(L, R, N, i + 1, l | (j > st), r | (j < ed));
  }
  return ans;
}