#include <bits/stdc++.h>
using namespace std;


template<typename Tp = int32_t>
struct sparse_table {
  vector<vector<Tp>> st;
  vector<Tp> lgs;
  int n, lg;
  function<Tp(Tp, Tp)> op;

  explicit sparse_table(const vector<Tp>& a, const function<Tp(Tp, Tp)>& op = [](Tp x, Tp y) -> Tp { return min(x, y); }) {
    sparse_table::n = (int) a.size();
    sparse_table::lg = __lg(sparse_table::n) + 1;
    sparse_table::lgs.resize(sparse_table::n + 1);
    sparse_table::st.resize(n, vector<Tp>(sparse_table::lg, 0));
    sparse_table::op = op;
    sparse_table::init(a);
  }

  void init(const vector<Tp>& a) {
    for (int i = 0; i < n; ++i) st[i][0] = a[i], lgs[i + 1] = __lg(i + 1);
    for (int j = 1; j < lg; ++j) {
      for (int i = 0; i + (1 << j) - 1 < n; ++i) {
        st[i][j] = op(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
      }
    }
  }
  Tp query(int L, int R) {
    int lg = lgs[R - L + 1];
    return op(st[L][lg], st[R - (1 << lg) + 1][lg]);
  }

  Tp query_d(int L, int R) {
    Tp sum = 0;
    while (L <= R) {
      int lg = lgs[R - L + 1];
      sum += st[L][lg];
      L += (1 << lg);
    }
    return sum;
  }
};


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> a = {1, 2, 3, 4, 5};

  auto max_ = [&](int x, int y) {
    return max(x, y);
  };
  sparse_table<int> st0(a, max_);
  sparse_table<int> st1(a);// default min

  cout << st0.query(0, 4) << '\n';
  cout << st1.query(0, 4) << '\n';

  return 0;
}