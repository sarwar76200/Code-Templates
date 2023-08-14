#include <bits/stdc++.h>
using namespace std;

static const int BASE = 1000000000;
static const int UPPER_BOUND = 999999999;
static const int DIGIT_COUNT = 9;
static const int powersOfTen[] = {1,      10,      100,      1000,     10000,
                                  100000, 1000000, 10000000, 100000000};

inline static div_t my_div(int num, int denom) {
  div_t result;
  result.quot = num / denom;
  result.rem = num - denom * result.quot;
  return result;
}

inline static lldiv_t my_lldiv(int64_t num, int64_t denom) {
  lldiv_t result;
  result.quot = num / denom;
  result.rem = num - denom * result.quot;
  return result;
}

class big_int {
  friend std::ostream &operator<<(std::ostream &s, const big_int &n);
  friend std::istream &operator>>(std::istream &s, big_int &val);

public:
  /* constructors */
  big_int();
  big_int(const char *c);
  big_int(const std::string &s);
  big_int(int l);
  big_int(int64_t l);
  big_int(uint32_t l);
  big_int(uint64_t l);
  big_int(const big_int &l);

  /* assignment operators */
  const big_int &operator=(const char *c);
  const big_int &operator=(const std::string &s);
  const big_int &operator=(int l);
  const big_int &operator=(int64_t l);
  const big_int &operator=(uint32_t l);
  const big_int &operator=(uint64_t l);
  const big_int &operator=(const big_int &l);

  /* unary increment/decrement operators */
  const big_int &operator++();
  const big_int &operator--();
  big_int operator++(int);
  big_int operator--(int);

  /* operational assignments */
  const big_int &operator+=(const big_int &rhs);
  const big_int &operator-=(const big_int &rhs);
  const big_int &operator*=(const big_int &rhs);
  const big_int &operator/=(const big_int &rhs);
  const big_int &operator%=(const big_int &rhs);
  const big_int &operator*=(int rhs);

  /* operations */
  big_int operator-() const;
  big_int operator+(const big_int &rhs) const;
  big_int operator-(const big_int &rhs) const;
  big_int operator*(const big_int &rhs) const;
  big_int operator/(const big_int &rhs) const;
  big_int operator%(const big_int &rhs) const;
  big_int operator*(int rhs) const;

  /* relational operations */
  bool operator==(const big_int &rhs) const;
  bool operator!=(const big_int &rhs) const;
  bool operator<(const big_int &rhs) const;
  bool operator<=(const big_int &rhs) const;
  bool operator>(const big_int &rhs) const;
  bool operator>=(const big_int &rhs) const;

  /* integer square root */
  big_int int_sqrt() const;

  /* digit operations */
  char digit_at(size_t i) const;
  size_t no_of_digits() const;

  /* size in bytes */
  size_t size() const;

  /* string conversion */
  std::string to_string() const;

  /* conversion to primitive types */
  int to_int() const;
  int64_t to_llong() const;
  uint32_t to_uint() const;
  uint64_t to_ullong() const;

private:
  static int d_i_n_r(const big_int &R, const big_int &D);
  static void multiply_by_digit(int factor, std::vector<int> &val);

  void correct(bool check_leading_zeros = false, bool has_valid_sign = false);
  void from_string(const std::string &s);
  void optimize_sqrt_search_bounds(big_int &lo, big_int &hi) const;
  void truncate_to_base();
  bool equalize_signs();
  void remove_leading_zeros();

  std::vector<int> val;
  bool pos;
};

inline big_int::big_int() : pos(true) { val.push_back((int)0); }

inline big_int::big_int(const char *c) { from_string(c); }

inline big_int::big_int(const std::string &s) { from_string(s); }

inline big_int::big_int(int l) : pos(l >= 0) {
  bool subtract_one = false;
  if (l == INT_MIN) {
    subtract_one = true;
    ++l;
  }
  if (!pos)
    l = -l;
  do {
    div_t dt = my_div(l, BASE);
    val.push_back((int)dt.rem);
    l = dt.quot;
  } while (l > 0);

  if (subtract_one)
    --*this;
}

inline big_int::big_int(int64_t l) : pos(l >= 0) {
  bool subtract_one = false;
  if (l == INT64_MIN) {
    subtract_one = true;
    ++l;
  }
  if (!pos)
    l = -l;

  do {
    lldiv_t dt = my_lldiv(l, BASE);
    val.push_back((int)dt.rem);
    l = dt.quot;
  } while (l > 0);

  if (subtract_one)
    --*this;
}

inline big_int::big_int(uint32_t l) : pos(true) {
  do {
    val.push_back((int)(l % BASE));
    l = l / BASE;
  } while (l > 0);
}

inline big_int::big_int(uint64_t l) : pos(true) {
  do {
    val.push_back((int)(l % BASE));
    l = l / BASE;
  } while (l > 0);
}

inline big_int::big_int(const big_int &l) : pos(l.pos), val(l.val) {}

inline const big_int &big_int::operator=(const char *c) {
  from_string(c);
  return *this;
}

inline const big_int &big_int::operator=(const std::string &s) {
  from_string(s);
  return *this;
}

inline const big_int &big_int::operator=(int l) {
  bool subtract_one = false;
  if (l == INT_MIN) {
    subtract_one = true;
    ++l;
  }
  pos = l >= 0;
  val.clear();
  if (!pos) {
    l = -l;
  }
  do {
    div_t dt = my_div(l, BASE);
    val.push_back((int)dt.rem);
    l = dt.quot;
  } while (l > 0);
  return subtract_one ? --*this : *this;
}

inline const big_int &big_int::operator=(int64_t l) {
  bool subtract_one = false;
  if (l == INT64_MIN) {
    subtract_one = true;
    ++l;
  }
  pos = l >= 0;
  val.clear();
  if (!pos) {
    l = -l;
  }
  do {
    lldiv_t dt = my_lldiv(l, BASE);
    val.push_back((int)dt.rem);
    l = dt.quot;
  } while (l > 0);
  return subtract_one ? --*this : *this;
}

inline const big_int &big_int::operator=(uint32_t l) {
  pos = true;
  val.clear();
  do {
    val.push_back((int)(l % BASE));
    l = l / BASE;
  } while (l > 0);
  return *this;
}

inline const big_int &big_int::operator=(uint64_t l) {
  pos = true;
  val.clear();
  do {
    val.push_back((int)(l % BASE));
    l = l / BASE;
  } while (l > 0);
  return *this;
}

inline const big_int &big_int::operator=(const big_int &l) {
  pos = l.pos;
  val = l.val;
  return *this;
}

inline const big_int &big_int::operator++() {
  val[0] += (pos ? 1 : -1);
  this->correct(false, true);
  return *this;
}

inline const big_int &big_int::operator--() {
  val[0] -= (pos ? 1 : -1);
  this->correct(false, true);
  return *this;
}

inline big_int big_int::operator++(int) {
  big_int result = *this;
  val[0] += (pos ? 1 : -1);
  this->correct(false, true);
  return result;
}

inline big_int big_int::operator--(int) {
  big_int result = *this;
  val[0] -= (pos ? 1 : -1);
  this->correct(false, true);
  return result;
}

inline const big_int &big_int::operator+=(const big_int &rhs) {
  if (rhs.val.size() > val.size()) {
    val.resize(rhs.val.size(), 0);
  }
  for (size_t i = 0; i < val.size(); ++i) {
    val[i] = (pos ? val[i] : -val[i]) +
             (i < rhs.val.size() ? (rhs.pos ? rhs.val[i] : -rhs.val[i]) : 0);
  }
  correct();
  return *this;
}

inline const big_int &big_int::operator-=(const big_int &rhs) {
  if (rhs.val.size() > val.size()) {
    val.resize(rhs.val.size(), 0);
  }
  for (size_t i = 0; i < val.size(); ++i) {
    val[i] = (pos ? val[i] : -val[i]) -
             (i < rhs.val.size() ? (rhs.pos ? rhs.val[i] : -rhs.val[i]) : 0);
  }
  correct();
  return *this;
}

inline const big_int &big_int::operator*=(const big_int &rhs) {
  *this = *this * rhs;
  return *this;
}

inline const big_int &big_int::operator/=(const big_int &rhs) {
  if (rhs == 0) {
    std::cerr << "Division by zero!" << std::endl;
    return *this;
  }
  big_int R, D = (rhs.pos ? rhs : -rhs), N = (pos ? *this : -*this);
  bool old_pos = pos;
  std::fill(val.begin(), val.end(), 0);
  for (int i = (int)N.val.size() - 1; i >= 0; --i) {
    R.val.insert(R.val.begin(), N.val[i]);
    R.correct(true);
    int cnt = d_i_n_r(R, D);
    R -= D * cnt;
    val[i] += cnt;
  }
  correct();
  pos = (val.size() == 1 && val[0] == 0) ? true : (old_pos == rhs.pos);
  return *this;
}

inline const big_int &big_int::operator%=(const big_int &rhs) {
  *this = *this % rhs;
  return *this;
}

inline const big_int &big_int::operator*=(int rhs) {
  int factor = rhs < 0 ? -rhs : rhs;
  bool old_pos = pos;
  multiply_by_digit(factor, val);
  correct();
  pos = (val.size() == 1 && val[0] == 0) ? true : (old_pos == (rhs >= 0));
  return *this;
}

inline big_int big_int::operator-() const {
  big_int result = *this;
  result.pos = !pos;
  return result;
}

inline big_int big_int::operator+(const big_int &rhs) const {
  big_int result;
  result.val.resize(val.size() > rhs.val.size() ? val.size() : rhs.val.size(),
                    0);
  for (size_t i = 0; i < val.size() || i < rhs.val.size(); ++i) {
    result.val[i] =
        (i < val.size() ? (pos ? val[i] : -val[i]) : 0) +
        (i < rhs.val.size() ? (rhs.pos ? rhs.val[i] : -rhs.val[i]) : 0);
  }
  result.correct();
  return result;
}

inline big_int big_int::operator-(const big_int &rhs) const {
  big_int result;
  result.val.resize(val.size() > rhs.val.size() ? val.size() : rhs.val.size(),
                    0);
  for (size_t i = 0; i < val.size() || i < rhs.val.size(); ++i) {
    result.val[i] =
        (i < val.size() ? (pos ? val[i] : -val[i]) : 0) -
        (i < rhs.val.size() ? (rhs.pos ? rhs.val[i] : -rhs.val[i]) : 0);
  }
  result.correct();
  return result;
}

inline big_int big_int::operator*(const big_int &rhs) const {
  big_int result;
  result.val.resize(val.size() + rhs.val.size(), 0);
  int64_t carry = 0;
  size_t digit = 0;
  for (;; ++digit) {
    lldiv_t dt = my_lldiv(carry, BASE);
    carry = dt.quot;
    result.val[digit] = (int)dt.rem;

    bool found = false;
    for (size_t i = digit < rhs.val.size() ? 0 : digit - rhs.val.size() + 1;
         i < val.size() && i <= digit; ++i) {
      int64_t pval = result.val[digit] + val[i] * (int64_t)rhs.val[digit - i];
      if (pval >= BASE || pval <= -BASE) {
        lldiv_t dt = my_lldiv(pval, BASE);
        carry += dt.quot;
        pval = dt.rem;
      }
      result.val[digit] = (int)pval;
      found = true;
    }
    if (!found) {
      break;
    }
  }
  for (; carry > 0; ++digit) {
    lldiv_t dt = my_lldiv(carry, BASE);
    result.val[digit] = (int)dt.rem;
    carry = dt.quot;
  }
  result.correct();
  result.pos =
      (result.val.size() == 1 && result.val[0] == 0) ? true : (pos == rhs.pos);
  return result;
}

inline big_int big_int::operator/(const big_int &rhs) const {
  if (rhs == 0) {
    std::cerr << "Division by zero!" << std::endl;
    return 0;
  }
  big_int Q, R, D = (rhs.pos ? rhs : -rhs), N = (pos ? *this : -*this);
  Q.val.resize(N.val.size(), 0);
  for (int i = (int)N.val.size() - 1; i >= 0; --i) {
    R.val.insert(R.val.begin(), N.val[i]);
    R.correct(true);
    int cnt = d_i_n_r(R, D);
    R -= D * cnt;
    Q.val[i] += cnt;
  }
  Q.correct();
  Q.pos = (Q.val.size() == 1 && Q.val[0] == 0) ? true : (pos == rhs.pos);
  return Q;
}

inline big_int big_int::operator%(const big_int &rhs) const {
  if (rhs == 0) {
    std::cerr << "Division by zero!" << std::endl;
    return 0;
  }
  big_int R, D = (rhs.pos ? rhs : -rhs), N = (pos ? *this : -*this);
  for (int i = (int)N.val.size() - 1; i >= 0; --i) {
    R.val.insert(R.val.begin(), N.val[i]);
    R.correct(true);
    R -= D * d_i_n_r(R, D);
  }
  R.correct();
  R.pos = (R.val.size() == 1 && R.val[0] == 0) ? true : pos;
  return R;
}

inline big_int big_int::operator*(int rhs) const {
  big_int result = *this;
  int factor = rhs < 0 ? -rhs : rhs;
  multiply_by_digit(factor, result.val);
  result.correct();
  result.pos = (result.val.size() == 1 && result.val[0] == 0)
                   ? true
                   : (pos == (rhs >= 0));
  return result;
}

inline bool big_int::operator==(const big_int &rhs) const {
  if (pos != rhs.pos || val.size() != rhs.val.size()) {
    return false;
  }
  for (int i = (int)val.size() - 1; i >= 0; --i) {
    if (val[i] != rhs.val[i]) {
      return false;
    }
  }
  return true;
}

inline bool big_int::operator!=(const big_int &rhs) const {
  return !(*this == rhs);
}

inline bool big_int::operator<(const big_int &rhs) const {
  if (pos && !rhs.pos) {
    return false;
  }
  if (!pos && rhs.pos) {
    return true;
  }
  if (val.size() > rhs.val.size()) {
    return pos ? false : true;
  }
  if (val.size() < rhs.val.size()) {
    return pos ? true : false;
  }
  for (int i = (int)val.size() - 1; i >= 0; --i) {
    if (val[i] < rhs.val[i]) {
      return pos ? true : false;
    }
    if (val[i] > rhs.val[i]) {
      return pos ? false : true;
    }
  }
  return false;
}

inline bool big_int::operator<=(const big_int &rhs) const {
  return (*this < rhs) || (*this == rhs);
}

inline bool big_int::operator>(const big_int &rhs) const {
  return !(*this <= rhs);
}

inline bool big_int::operator>=(const big_int &rhs) const {
  return !(*this > rhs);
}

inline void big_int::optimize_sqrt_search_bounds(big_int &lo,
                                                 big_int &hi) const {
  big_int hdn = 1;
  for (int i = (int)this->no_of_digits() / 2; i >= 2; --i) {
    hdn *= 10;
  }
  if (lo < hdn) {
    lo = hdn;
  }
  hdn *= 100;
  if (hi > hdn) {
    hi = hdn;
  }
}

inline big_int big_int::int_sqrt() const {
  if (*this <= 0) {
    std::cerr << "int_sqrt called for non-positive integer: " << *this
              << std::endl;
    return 0;
  }
  big_int hi = *this / 2 + 1, lo = 0, mid, mid2;
  optimize_sqrt_search_bounds(lo, hi);
  do {
    mid = (hi + lo) / 2;
    mid2 = mid * mid;
    if (mid2 == *this) {
      lo = mid;
      break;
    } else if (mid2 < *this) {
      lo = mid;
    } else {
      hi = mid;
    }
  } while (lo < hi - 1 && mid2 != *this);
  return lo;
}

inline char big_int::digit_at(size_t i) const {
  if (no_of_digits() <= i) {
    std::cerr << "Invalid digit index: " << i << std::endl;
    return -1;
  }
  return (val[i / DIGIT_COUNT] / powersOfTen[i % DIGIT_COUNT]) % 10;
}

inline size_t big_int::no_of_digits() const {
  return (val.size() - 1) * DIGIT_COUNT +
         (val.back() > 99999999
              ? 9
              : (val.back() > 9999999
                     ? 8
                     : (val.back() > 999999
                            ? 7
                            : (val.back() > 99999
                                   ? 6
                                   : (val.back() > 9999
                                          ? 5
                                          : (val.back() > 999
                                                 ? 4
                                                 : (val.back() > 99
                                                        ? 3
                                                        : (val.back() > 9
                                                               ? 2
                                                               : 1))))))));
}

inline std::string big_int::to_string() const {
  std::ostringstream oss;
  oss << *this;
  return oss.str();
}

inline size_t big_int::size() const {
  return val.size() * sizeof(int) + sizeof(bool);
}

inline int big_int::to_int() const {
  if (*this > INT_MAX || *this < INT_MIN) {
    std::cerr << "Out of INT bounds: " << *this << std::endl;
  }
  int result = 0;
  for (int i = (int)val.size() - 1; i >= 0; --i) {
    result = result * BASE + val[i];
  }
  return pos ? result : -result;
}

inline int64_t big_int::to_llong() const {
  if (*this > INT64_MAX || *this < INT64_MIN) {
    std::cerr << "Out of LLONG bounds: " << *this << std::endl;
  }
  int64_t result = 0;
  for (int i = (int)val.size() - 1; i >= 0; --i) {
    result = result * BASE + val[i];
  }
  return pos ? result : -result;
}

inline uint32_t big_int::to_uint() const {
  if (!pos || *this > UINT_MAX) {
    std::cerr << "Out of UINT bounds: " << *this << std::endl;
  }
  uint32_t result = 0;
  for (int i = (int)val.size() - 1; i >= 0; --i) {
    result = result * BASE + val[i];
  }
  return result;
}

inline uint64_t big_int::to_ullong() const {
  if (!pos || *this > UINT64_MAX) {
    std::cerr << "Out of ULLONG bounds: " << *this << std::endl;
  }
  uint64_t result = 0;
  for (int i = (int)val.size() - 1; i >= 0; --i) {
    result = result * BASE + val[i];
  }
  return result;
}

inline void big_int::truncate_to_base() {
  for (size_t i = 0; i < val.size(); ++i) {
    if (val[i] >= BASE || val[i] <= -BASE) {
      div_t dt = my_div(val[i], BASE);
      val[i] = dt.rem;
      if (i + 1 >= val.size()) {
        val.push_back(dt.quot);
      } else {
        val[i + 1] += dt.quot;
      }
    }
  }
}

inline bool big_int::equalize_signs() {
  bool isPositive = true;
  int i = (int)((val.size())) - 1;
  for (; i >= 0; --i) {
    if (val[i] != 0) {
      isPositive = val[i--] > 0;
      break;
    }
  }
  if (isPositive) {
    for (; i >= 0; --i) {
      if (val[i] < 0) {
        int k = 0, index = i + 1;
        for (; (size_t)(index) < val.size() && val[index] == 0; ++k, ++index)
          ;
        {
          val[index] -= 1;
          val[i] += BASE;
          for (; k > 0; --k) {
            val[i + k] = UPPER_BOUND;
          }
        }
      }
    }
  } else {
    for (; i >= 0; --i) {
      if (val[i] > 0) {
        int k = 0, index = i + 1;
        for (; (size_t)(index) < val.size() && val[index] == 0; ++k, ++index)
          ;
        {
          val[index] += 1;
          val[i] -= BASE;
          for (; k > 0; --k) {
            val[i + k] = -UPPER_BOUND;
          }
        }
      }
    }
  }
  return isPositive;
}

inline void big_int::remove_leading_zeros() {
  for (int i = (int)(val.size()) - 1; i > 0; --i) {
    if (val[i] != 0) {
      return;
    } else {
      val.erase(val.begin() + i);
    }
  }
}

inline void big_int::correct(bool check_leading_zeros, bool has_valid_sign) {
  if (!check_leading_zeros) {
    truncate_to_base();
    if (equalize_signs()) {
      pos = ((val.size() == 1 && val[0] == 0) || !has_valid_sign) ? true : pos;
    } else {
      pos = has_valid_sign ? !pos : false;
      for (int &i : val) {
        i = abs(i);
      }
    }
  }
  remove_leading_zeros();
}

inline void big_int::from_string(const std::string &s) {
  pos = true;
  val.clear();
  val.reserve(s.size() / DIGIT_COUNT + 1);
  int i = (int)s.size() - DIGIT_COUNT;
  for (; i >= 0; i -= DIGIT_COUNT) {
    val.push_back(atoi(s.substr(i, DIGIT_COUNT).c_str()));
  }
  if (i > -DIGIT_COUNT) {
    std::string ss = s.substr(0, i + DIGIT_COUNT);
    if (ss.size() == 1 && ss[0] == '-') {
      pos = false;
    } else {
      val.push_back(atoi(ss.c_str()));
    }
  }
  if (val.back() < 0) {
    val.back() = -val.back();
    pos = false;
  }
  correct(true);
}

inline int big_int::d_i_n_r(const big_int &R, const big_int &D) {
  int min = 0, max = UPPER_BOUND;
  while (max > min) {
    int avg = max + min;
    div_t dt = my_div(avg, 2);
    avg = dt.rem ? (dt.quot + 1) : dt.quot;
    big_int prod = D * avg;
    if (R == prod) {
      return avg;
    } else if (R > prod) {
      min = avg;
    } else {
      max = avg - 1;
    }
  }
  return min;
}

inline void big_int::multiply_by_digit(int factor, std::vector<int> &val) {
  int carry = 0;
  for (int &i : val) {
    int64_t pval = i * (int64_t)factor + carry;
    if (pval >= BASE || pval <= -BASE) {
      lldiv_t dt = my_lldiv(pval, BASE);
      carry = (int)dt.quot;
      pval = dt.rem;
    } else {
      carry = 0;
    }
    i = (int)pval;
  }
  if (carry > 0) {
    val.push_back(carry);
  }
}

inline std::istream &operator>>(std::istream &s, big_int &n) {
  std::string str;
  s >> str;
  n.from_string(str);
  return s;
}
inline std::ostream &operator<<(std::ostream &s, const big_int &n) {
  if (!n.pos)
    s << '-';
  bool first = true;
  for (int i = int(n.val.size()) - 1; i >= 0; --i) {
    if (first) {
      s << n.val[i];
      first = false;
    } else {
      s << std::setfill('0') << std::setw(DIGIT_COUNT) << n.val[i];
    }
  }
  return s;
}

void run_case(int tc) {
  big_int a = 100;
  big_int b = big_int("12345");
  cout << a * b << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  //   cin >> t;
  for (int tc = 1; tc <= t; ++tc) {
    run_case(tc);
  }

  return 0;
}