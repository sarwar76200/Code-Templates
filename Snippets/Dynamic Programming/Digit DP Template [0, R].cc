int count(const string& R, int N, int i = 0, bool r = false) {
  if (i == N) {
    return 0;
  }
  int ans = 0;
  int ed = r ? 9 : R[i] - '0';
  for (int j = 0; j <= ed; ++j) {
    ans += count(R, N, i + 1, r | (j < ed));
  }
  return ans;
}