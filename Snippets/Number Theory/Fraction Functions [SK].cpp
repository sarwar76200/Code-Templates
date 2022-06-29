pair<ll, ll> frac_add(pair<ll, ll> a, pair<ll, ll> b)
{
    ll g = a.second * b.second;
    pair<ll, ll> x;
    x.second = g;
    x.first = a.first * (b.second) + b.first * (a.second);
    ll y = __gcd(x.first, x.second);
    x.first /= y;
    x.second /= y;
    return x;
}
pair<ll, ll> frac_mult(pair<ll, ll> a, pair<ll, ll> b)
{

    pair<ll, ll> x;

    x.first = a.first * b.first;
    x.second = a.second * b.second;
    ll y = __gcd(x.first, x.second);
    x.first /= y;
    x.second /= y;
    return x;
}
