ll mul(ll x, ll y, ll mod) {
    ll res = 0;
    x %= mod;
    while (y) {
        if (y & 1) res = (res + x) % mod;
        y >>= 1;
        x = (x + x) % mod;
    }
    return res;
}
ll bigmod(ll a, ll m, ll mod) {
    a = a % mod;
    ll res = 1ll;
    while (m > 0) {
        if (m & 1) res = mul(res, a, mod);
        m >>= 1;
        a = mul(a, a, mod);
    }
    return res;
}
bool composite(ll n, ll a, ll s, ll d) {
    ll x = bigmod(a, d, n);
    if (x == 1 or x == n - 1) return false;
    for (int r = 1; r < s; r++) {
        x = mul(x, x, n);
        if (x == n - 1) return false;
    }
    return true;
}
bool isprime(ll n) {
    if (n < 4) return n == 2 or n == 3;
    if (n % 2 == 0) return false;
    ll d = n - 1;
    ll s = 0;
    while (d % 2 == 0) {
        d /= 2;
        s++;
    }
    for (int i = 0; i < 10; i++) {
        ll a = 2 + rand() % (n - 3);
        if (composite(n, a, s, d)) return false;
    }
    return true;
}
// Polard rho
ll f(ll x, ll c, ll mod) {
    return (mul(x, x, mod) + c) % mod;
}
ll rho(ll n) {
    if (n % 2 == 0) {
        return 2;
    }
    ll x = rand() % n + 1;
    ll y = x;
    ll c = rand() % n + 1;
    ll g = 1;
    while (g == 1) {
        x = f(x, c, n);
        y = f(y, c, n);
        y = f(y, c, n);
        g = __gcd(abs(y - x), n);
    }
    return g;
}
void factorize(ll n, vector<ll>& factors) {
    if (n == 1) {
        return;
    }
    else if (isprime(n)) {
        factors.push_back(n);
        return;
    }
    ll cur = n;
    for (ll c = 1; cur == n; c++) {
        cur = rho(n);
    }
    factorize(cur, factors), factorize(n / cur, factors);
}