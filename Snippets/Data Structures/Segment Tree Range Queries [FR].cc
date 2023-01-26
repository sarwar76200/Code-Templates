const int N = 1e5 + 5;
int arr[N + 1], Tree[4 * N + 10];
int n;

void build(int ind = 1, int l = 0, int r = n - 1) {
    if (l == r) {
        Tree[ind] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * ind, l, mid);
    build((2 * ind) + 1, mid + 1, r);
    Tree[ind] = Tree[2 * ind] * Tree[(2 * ind) + 1];
}

int get_queries(int& a, int& b, int ind = 1, int l = 0, int r = n - 1) {
    if (l >= a && r <= b) {
        return Tree[ind];
    }
    if (l > b || r < a) {
        return 1;
    }
    int mid = (l + r) / 2;
    int lt = get_queries(a, b, 2 * ind, l, mid);
    int rt = get_queries(a, b, (2 * ind) + 1, mid + 1, r);
    return lt * rt;
}

void update(int& pos, int& val, int ind = 1, int l = 0, int r = n - 1) {
    if (pos < l || pos > r) {
        return;
    }
    if (l == r) {
        arr[l] = val;
        Tree[ind] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) {
        update(pos, val, 2 * ind, l, mid);
    } else {
        update(pos, val, (2 * ind) + 1, mid + 1, r);
    }
    Tree[ind] = Tree[2 * ind] * Tree[(2 * ind) + 1];
}