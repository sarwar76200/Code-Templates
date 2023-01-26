struct Node {
    int64_t fwd, rev;
    int len;
    Node(int64_t f, int64_t r, int l) {
        fwd = f, rev = r, len = l;
    }
    Node() {
        fwd = rev = len = 0;
    }
};

const int BASE = 47, MX_N = 1E5 + 5, M = 1E9 + 7;
string a;
Node st[4 * MX_N];
int64_t expo[MX_N];// TODO: compute this beforehand

void build(int node, int tL, int tR) {
    if (tL == tR) {
        st[node] = Node(a[tL], a[tL], 1);
        return;
    }
    int mid = (tL + tR) / 2;
    int left = 2 * node, right = 2 * node + 1;
    build(left, tL, mid);
    build(right, mid + 1, tR);
    st[node] = Node((st[left].fwd * expo[st[right].len] + st[right].fwd) % M,
                    (st[right].rev * expo[st[left].len] + st[left].rev) % M,
                    st[left].len + st[right].len);
}

void update(int node, int tL, int tR, int i, int64_t v) {
    if (tL >= i && tR <= i) {
        st[node] = Node(v, v, 1);
        return;
    }
    if (tR < i || tL > i) return;

    int mid = (tL + tR) / 2;
    int left = 2 * node, right = 2 * node + 1;
    update(left, tL, mid, i, v);
    update(right, mid + 1, tR, i, v);
    st[node] = Node((st[left].fwd * expo[st[right].len] + st[right].fwd) % M,
                    (st[right].rev * expo[st[left].len] + st[left].rev) % M,
                    st[left].len + st[right].len);
}

Node query(int node, int tL, int tR, int qL, int qR) {
    if (tL >= qL && tR <= qR) {
        return Node(st[node].fwd, st[node].rev, st[node].len);
    }
    if (tR < qL || tL > qR) {
        return Node(0, 0, 0);
    }
    int mid = (tL + tR) / 2;
    auto QL = query(2 * node, tL, mid, qL, qR);
    auto QR = query(2 * node + 1, mid + 1, tR, qL, qR);
    return Node((QL.fwd * expo[QR.len] + QR.fwd) % M, (QR.rev * expo[QL.len] + QL.rev) % M, QL.len + QR.len);
}