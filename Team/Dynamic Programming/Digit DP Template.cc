int count(string& L, string& R, int N, int i = 0, bool l = false, bool r = false) {
  if (i == N) return 1;

  int ans = 0;
  int st = l ? 0 : (L[i] - '0'), ed = r ? 9 : (R[i] - '0');
  for (int j = st; j <= ed; ++j) {
    ans += count(L, R, N, i, l | (j > st), r | (j < ed));
  }
  return ans;
}