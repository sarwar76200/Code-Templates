const int N = 1e5 + 5;
ll v[4 * N];
ll add[4 * N];
int arr[N];

void push(int cur)
{
    add[cur * 2] += add[cur];
    add[cur * 2 + 1] += add[cur];
    add[cur] = 0;
}
void build(int cur, int l, int r)
{
    if (l == r)
    {
        v[cur] = arr[l];
        return;
    }

    int mid = l + (r - l) / 2;

    build(cur * 2, l, mid);
    build(cur * 2 + 1, mid + 1, r);

    v[cur] = v[cur * 2] + v[cur * 2 + 1];

    return;
}
ll query(int cur, int l, int r, int x, int y)
{

    if (x > r || y < l)
    {
        return 0;
    }
    if (l == r)
    {
        return v[cur] + add[cur];
    }
    if (l == x && r == y)
    {
        return v[cur] + add[cur] * (r - l + 1);
    }
    int mid = l + (r - l) / 2;

    v[cur] += add[cur] * (r - l + 1);
    push(cur);

    ll left = query(cur * 2, l, mid, x, min(mid, y));
    ll right = query(cur * 2 + 1, mid + 1, r, max(mid + 1, x), y);

    ll res = 0;
    res = left + right;

    return res;
}
void update(int cur, int l, int r, int s, int e, int val)
{
    if (l == s && r == e)
    {
        add[cur] += val;
        return;
    }

    if (s > r || e < l)
    {
        return;
    }

    int mid = l + (r - l) / 2;

    push(cur);

    update(cur * 2, l, mid, s, min(e, mid), val);
    update(cur * 2 + 1, mid + 1, r, max(s, mid + 1), e, val);

    v[cur] = (v[cur * 2] + add[cur * 2] * (mid - l + 1)) + (v[cur * 2 + 1] + add[cur * 2 + 1] * (r - mid));
    return;
}