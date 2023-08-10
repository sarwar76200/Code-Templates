const int N = 100001, LG = 18;
int st[N][LG];

void sparse_table(vector<int>& a, int n) {
    for (int i = 0; i < n; ++i) {
        st[i][0] = a[i];
    }

    for (int j = 1; j < LG; ++j) {
        for (int i = 0; i + (1 << j) - 1 < n; ++i) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int rmq(int L, int R) {
    int lg = __lg(R - L + 1);
    return min(st[L][lg], st[R - (1 << lg) + 1][lg]);
}