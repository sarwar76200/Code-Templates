int ternary_search(vector<int>& a, int l, int r) {
  double eps = 1e-9;//set the error limit here
  while (l <= r) {
    int m1 = l + (r - l) / 3;
    int m2 = r - (r - l) / 3;
    int f1 = f(a, m1);//evaluates the function at m1
    int f2 = f(a, m2);//evaluates the function at m2
    if (f1 < f2)
      r = m2 - 1;
    else
      l = m1 + 1;
  }
  return a[r];//return the min element
}
int ternary_search(vector<int>& a, int l, int r) {
  double eps = 1e-9;//set the error limit here
  while (l <= r) {
    int m1 = l + (r - l) / 3;
    int m2 = r - (r - l) / 3;
    int f1 = f(a, m1);//evaluates the function at m1
    int f2 = f(a, m2);//evaluates the function at m2
    if (f1 < f2)
      l = m1 + 1;
    else
      r = m2 - 1;
  }
  return a[l];//return the max element
}