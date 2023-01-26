const int N = 1e5 + 5;
int arr[N + 1];
int Tree[4 * N + 10], Lazy[4 * N + 10];
int n;

void build(int ind = 1, int l = 0, int r = n - 1) {
    if (l == r) {
        Tree[ind] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * ind, l, mid);
    build((2 * ind) + 1, mid + 1, r);
    Tree[ind] = Tree[2 * ind] + Tree[(2 * ind) + 1];
}

void propagate(int ind, int l, int r) {
    Tree[ind] += (Lazy[ind] * (r - l + 1));
    Lazy[2 * ind] += Lazy[ind];
    Lazy[(2 * ind) + 1] += Lazy[ind];
    Lazy[ind] = 0;
}

ll get_queries(ll& a, ll& b, ll ind = 1, ll l = 0, ll r = n - 1) {
    if (l > b || r < a) {
        return 0;
    }
    if (l >= a && r <= b) {
        return Tree[ind] + (Lazy[ind] * (r - l + 1));
    }
    propagate(ind, l, r);
    ll mid = (l + r) / 2;
    ll lt = get_queries(a, b, 2 * ind, l, mid);
    ll rt = get_queries(a, b, (2 * ind) + 1, mid + 1, r);
    return lt + rt;
}

void lazyness(ll& a, ll& b, ll& val, ll ind = 1, ll l = 0, ll r = n - 1) {
    if (l > b || r < a) {
        return;
    }
    if (a <= l && b >= r) {
        Lazy[ind] += val;
        return;
    }
    propagate(ind, l, r);
    ll mid = (l + r) / 2;
    lazyness(a, b, val, 2 * ind, l, mid);
    lazyness(a, b, val, (2 * ind) + 1, mid + 1, r);
    Tree[ind] = Tree[2 * ind] + (Lazy[2 * ind] * (mid - l + 1)) + Tree[(2 * ind) + 1] + (Lazy[(2 * ind) + 1] * (r - mid));
}
