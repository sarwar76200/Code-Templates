#ifndef DEBUG_HPP
#define DEBUG_HPP

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename A, typename B>
using ordered_map =
    tree<A, B, less<A>, rb_tree_tag, tree_order_statistics_node_update>;

struct mint {
    const uint32_t M = 1000000007;
    uint64_t n;
    mint() { n = 0; }
    mint(int64_t n) { mint::n = n; }

    mint operator+(mint& other) { return (n % M + other.n % M) % M; }

    mint operator+(uint64_t other) { return (n % M + other % M) % M; }
    mint operator-(mint& other) { return (n % M - other.n % M) % M; }
    mint operator-(uint64_t other) { return (n % M - other % M) % M; }

    uint64_t mul_mod(uint64_t a, uint64_t b) {
        uint64_t x = 0, y = a % M;
        while (b > 0) {
            if (b & 1)
                x = (x + y) % M;
            y = (y * 2) % M;
            b >>= 1;
        }
        return x % M;
    }
    uint64_t bin_expo(uint64_t b, uint64_t e) {
        b %= M;
        uint64_t res = 1;
        while (e > 0) {
            if (e & 1)
                res = b * res % M;
            b = b * b % M;
            e >>= 1;
        }
        return res;
    }
    uint64_t inv_mod(uint64_t a) { return bin_expo(a, M - 2); }
    mint operator*(mint& other) { return mul_mod(mint::n, other.n); }
    mint operator*(uint64_t other) { return mul_mod(mint::n, other); }
    mint operator/(mint& other) { return mint::n * inv_mod(other.n); }
    mint operator/(uint64_t other) { return mint::n * inv_mod(other); }
    mint& operator++() { return ++mint::n, *this; }
    mint operator++(int) { mint ret = *this; return ++mint::n, ret; }
    mint& operator=(mint other) { return mint::n = other.n, *this; }
    mint& operator+=(mint other) { return mint::n = mint::n + other.n, *this; }
    mint& operator-=(mint other) { return mint::n = mint::n - other.n, *this; }
    mint& operator*=(mint other) { return mint::n = mint::n * other.n, *this; }
    mint& operator/=(mint other) { return mint::n = mint::n / other.n, *this; }
};

ostream& operator<<(ostream& out, mint m) {
    out << m.n;
    return out;
}
istream& operator>>(istream& in, mint& m) {
    in >> m.n;
    return in;
}

/// Returns a random integer in the specified range
int randint(int l, int r) {
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist(l, r);
  return dist(mt);
}
/// Returns a random 64-bit integer in the specified range
int64_t randint64(int64_t l, int64_t r) {
  std::random_device rd;
  std::mt19937_64 mt(rd());
  std::uniform_int_distribution<int64_t> dist(l, r);
  return dist(mt);
}
/// Returns an vector of specified size containing integers in the specified
/// range
vector<int> int_array(int size, int range_l, int range_r) {
  vector<int> _a(size);
  for (int i = 0; i < size; ++i) {
    _a[i] = randint(range_l, range_r);
  }
  return _a;
}

string binary4(uint16_t _decimal) { return bitset<4>(_decimal).to_string(); }
string binary8(uint16_t _decimal) { return bitset<8>(_decimal).to_string(); }
string binary16(uint16_t _decimal) { return bitset<16>(_decimal).to_string(); }
string binary32(uint32_t _decimal) { return bitset<32>(_decimal).to_string(); }
string binary64(uint64_t _decimal) { return bitset<64>(_decimal).to_string(); }
string binary_fit(uint64_t _decimal) {
  string bin = bitset<64>(_decimal).to_string();
  bin.erase(0, min<int>(bin.find_first_not_of('0'), (int)bin.length() - 1));
  return bin;
}

vector<int64_t> int64_array(int size, int64_t range_l, int64_t range_r) {
  vector<int64_t> _a(size);
  for (int i = 0; i < size; ++i) {
    _a[i] = randint64(range_l, range_r);
  }
  return _a;
}
string randstring(int size, char range_l, char range_r) {
  string s = string(size, '?');
  for (int i = 0; i < size; ++i) {
    s[i] = char(randint(0, range_r - range_l) + range_l);
  }
  return s;
}
string randstring_m(int size, string chars) {
  string s = string(size, '?');
  for (int i = 0; i < size; ++i) {
    s[i] = chars[randint(0, (int)chars.size() - 1)];
  }
  return s;
}
string randstring(int size, vector<string> chars) {
  string _chars;
  for (auto &i : chars) {
    if (i.length() == 3U) {
      for (char c = i.front(); c <= i.back(); ++c) {
        _chars.push_back(c);
      }
    } else
      _chars.push_back(i.front());
  }

  return randstring_m(size, _chars);
}

struct uNode {
  int u, v;
  uNode(int _u, int _v) { u = _u, v = _v; }
};
vector<vector<int>> ugraph(int nodes, int edges) {
  assert(edges <= 1LL * nodes * (nodes - 1) / 2);

  set<vector<int>> _edges;
  while (edges > 0) {
    int u = randint(1, nodes);
    int v = randint(1, nodes);
    if (u == v)
      continue;
    if (u > v)
      swap(u, v);
    if (_edges.find({u, v}) == _edges.end()) {
      --edges;
    }
    _edges.insert({u, v});
  }
  return vector<vector<int>>(_edges.begin(), _edges.end());
}
vector<vector<int>> wgraph(int nodes, int edges, pair<int, int> weight_range) {
  assert(edges <= 1LL * nodes * (nodes - 1) / 2);

  set<vector<int>> _edges;
  vector<vector<int>> _adj;
  while (edges > 0) {
    int u = randint(1, nodes);
    int v = randint(1, nodes);
    int c = randint(weight_range.first, weight_range.second);
    if (u == v)
      continue;
    if (u > v)
      swap(u, v);
    if (_edges.find({u, v}) == _edges.end()) {
      _adj.push_back({u, v, c});
      --edges;
    }
    _edges.insert({u, v});
  }
  return _adj;
}

template <typename type>
ostream &operator<<(ostream &out, const vector<type> &v) {
  for (const type &i : v)
    out << i << ' ';
  return out;
}
template <typename type>
ostream &operator<<(ostream &out, const vector<vector<type>> &v) {
  for (const vector<type> &i : v)
    out << i << '\n';
  return out;
}
template <typename type> ostream &operator<<(ostream &out, const set<type> &s) {
  for (const type &i : s)
    out << i << ' ';
  return out;
}
template <typename type>
ostream &operator<<(ostream &out, const multiset<type> &ms) {
  for (const type &i : ms)
    out << i << ' ';
  return out;
}
template <typename A, typename B>
ostream &operator<<(ostream &out, const map<A, B> &mp) {
  for (const pair<const A, B> &i : mp) {
    out << '[' << i.first << ": " << i.second << ']' << '\n';
  }
  return out;
}
template <typename type>
ostream &operator<<(ostream &out, const queue<type> &q) {
  queue<type> r = q;
  while (!r.empty())
    out << r.front() << ' ', r.pop();
  return out;
}
template <typename type>
ostream &operator<<(ostream &out, const stack<type> &s) {
  stack<type> t = s;
  while (!t.empty())
    out << t.top() << ' ', t.pop();
  return out;
}
template <typename type> istream &operator>>(istream &in, vector<type> &v) {
  for (type &i : v)
    in >> i;
  return in;
}
template <typename type>
istream &operator>>(istream &in, vector<vector<type>> &v) {
  for (vector<type> &i : v)
    in >> i;
  return in;
}
template <typename type>
vector<int> operator+(const vector<type> &v, const vector<type> &w) {
  vector<type> r = v;
  for (const type &i : w)
    r.push_back(i);
  return r;
}
template <typename type>
set<int> operator|(const set<type> &s, const set<type> &t) {
  set<type> r;
  set_union(s.begin(), s.end(), t.begin(), t.end(), inserter(r, r.end()));
  return r;
}
template <typename type>
set<int> operator&(const set<type> &s, const set<type> &t) {
  set<type> r;
  set_intersection(s.begin(), s.end(), t.begin(), t.end(),
                   inserter(r, r.end()));
  return r;
}
template <typename A, typename B>
ostream &operator<<(ostream &out, pair<A, B> p) {
  out << "(" << p.first << ", " << p.second << ")";
  return out;
}
template <typename A, typename B, typename C>
ostream &operator<<(ostream &out, tuple<A, B, C> t) {
  out << "(" << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << ")";
  return out;
}

template <typename T> ostream &operator<<(ostream &out, ordered_set<T> st) {
  for (T i : st)
    out << i << " ";
  return out;
}
template <typename A, typename B>
ostream &operator<<(ostream &out, ordered_map<A, B> mp) {
  for (pair<A, B> i : mp)
    out << i << " ";
  return out;
}

template <typename c> struct rge { c b, e; };
template <typename c> rge<c> range(c i, c j) { return {i, j}; }
struct debugger {
  ~debugger() { cout << endl; }
  template <typename c> debugger &operator<<(c x) {
    cout << boolalpha << x;
    return *this;
  }
  debugger &operator<<(string x) {
    cout << x;
    return *this;
  }
  template <typename c, class d> debugger &operator<<(pair<c, d> x) {
    return *this << "(" << x.first << ", " << x.second << ")";
  }
  template <typename... d, template <typename...> class c>
  debugger &operator<<(c<d...> x) {
    return *this << range(begin(x), end(x));
  }
  template <typename c> debugger &operator<<(rge<c> x) {
    *this << "[";
    for (auto it = x.b; it != x.e; ++it)
      *this << (it == x.b ? "" : ", ") << *it;
    return *this << "]";
  }
};
#define dbg(x) "[" #x << ": " << (x) << "] "
#define cerr cout << "LINE " << __LINE__ << " >> ", debugger()
#define pause getchar()

#endif // DEBUG_HPP
