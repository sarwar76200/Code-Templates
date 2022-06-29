const long long int maxn = 100010;
long long int segtree[4 * maxn];
void build_seg_tree(long long int a[], long long int v, long long int tl, long long int tr)
{
    if (tl == tr)
    {
        segtree[v] = a[tl];
    }
    else
    {
        long long int tm = (tl + tr) / 2;
        build_seg_tree(a, v * 2, tl, tm);
        build_seg_tree(a, v * 2 + 1, tm + 1, tr);
        segtree[v] = segtree[v * 2] + segtree[v * 2 + 1];
    }
}
long long int get(long long int v, long long int tl, long long int tr, long long int l, long long int r)
{
    if (l > r)
    {
        return 0;
    }
    if (l == tl && r == tr)
    {
        return segtree[v];
    }
    long long int tm = (tl + tr) / 2;
    return get(v * 2, tl, tm, l, min(r, tm))
        + get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}
void update_seg_tree(long long int v, long long int tl, long long int tr, long long int pos, long long int new_val)
    {
    if (tl == tr)
    {
        segtree[v] = new_val;
    }
    else
    {
        long long int tm = (tl + tr) / 2;
        if (pos <= tm)
        {
            update_seg_tree(v * 2, tl, tm, pos, new_val);
        }
        else
        {
            update_seg_tree(v * 2 + 1, tm + 1, tr, pos, new_val);
        }
        segtree[v] = segtree[v * 2] + segtree[v * 2 + 1];
    }
}
