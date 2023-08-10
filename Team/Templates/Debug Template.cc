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

"For loop 0 based": {
		"prefix": "for0",
		"body": [
			"for (int ${1:i} = 0; ${1:i} < $2; ++${1:i}) {",
			"    $0",
			"}"
		],
		"description": "For loop"
	},
	
// "$a.begin(), $a.end()$0"