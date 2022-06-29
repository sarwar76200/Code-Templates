const long long int maxn = 100010;
long long int segtree[4 * maxn];
long long int lazy[4 * maxn];
long long int a[maxn];
void fix(int n)
{
    for (int i = 0; i < 4 * n; i++)
    {
        lazy[i] = 0;
        segtree[i] = 0;
    }
}
void build_seg_tree(long long int i, long long int lo, long long int hi)
{
    if (lo == hi)
    {
        segtree[i] = a[i];
        lazy[i] = 0;
        return;
    }
    long long int mid = (lo + hi) / 2;
    build_seg_tree(2 * i, lo, mid);
    build_seg_tree(2 * i + 1, mid + 1, hi);
    segtree[i] = segtree[2 * i] + segtree[2 * i + 1];
    lazy[i] = 0;
}
void push(long long int i)
{
    lazy[2 * i] += lazy[i];
    lazy[2 * i + 1] += lazy[i];
    lazy[i] = 0;
}
void update(long long int i, long long int lo, long long int hi, long long int l, long long int r, long long int val)
{
    if (r<lo || l>hi)
    {
        return;
    }
    if (l <= lo && hi <= r)
    {
        lazy[i] += val;
        return;
    }
    push(i);
    long long int mid = (lo + hi) / 2;
    update(2 * i, lo, mid, l, r, val);
    update(2 * i + 1, mid + 1, hi, l, r, val);
    segtree[i] = segtree[2 * i] + (mid - lo + 1) * lazy[2 * i] + segtree[2 * i + 1] + (hi - mid) * lazy[2 * i + 1];
}
long long int query(long long int i, long long int lo, long long int hi, long long int l, long long int r)
{
    if (r<lo || l>hi)
    {
        return 0;
    }
    if (l <= lo && hi <= r)
    {
        return segtree[i] + lazy[i] * (hi - lo + 1);
    }
    push(i);
    long long int mid = (lo + hi) / 2;
    long long int ans = query(2 * i, lo, mid, l, r) +
        query(2 * i + 1, mid + 1, hi, l, r);
    segtree[i] = segtree[2 * i] + (mid - lo + 1) * lazy[2 * i] + segtree[2 * i + 1] + (hi - mid) * lazy[2 * i + 1];
    return ans;
}