#include <bits/stdc++.h>

using namespace std;

const int N = 100001;
int a[N], tree[4 * N], lazy[4 * N];


// 0-based indexing
void build(int node, int tL, int tR) {
    if (tL == tR) {
        tree[node] = a[tL];
        return;
    }
    int mid = (tL + tR) / 2;

    build(2 * node, tL, mid);
    build(2 * node + 1, mid + 1, tR);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void update(int node, int tL, int tR, int qL, int qR, int val) {
    if (lazy[node] != 0) {
        tree[node] += (tR - tL + 1) * lazy[node];

        if (tL != tR) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (tR < qL || tL > qR) {
        return;
    }
    if (tL >= qL && tR <= qR) {
        tree[node] += (tR - tL + 1) * val;
        if (tL != tR) {
            lazy[2 * node] += val;
            lazy[2 * node + 1] += val;
        }
        return;
    }

    int mid = (tL + tR) / 2;

    update(2 * node, tL, mid, qL, qR, val);
    update(2 * node + 1, mid + 1, tR, qL, qR, val);

    tree[node] = (tree[2 * node] + tree[2 * node + 1]);
}

int query(int node, int tL, int tR, int l, int r) {
    if (lazy[node] != 0) {
        tree[node] += (tR - tL + 1) * lazy[node];
        if (tL != tR) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (tR < l || tL > r) {
        return 0;
    }

    if (l <= tL && tR <= r) {
        return tree[node];
    }
    int mid = (tL + tR) / 2;

    int QL = query(2 * node, tL, mid, l, r);
    int QR = query(2 * node + 1, mid + 1, tR, l, r);

    return QL + QR;
}
// https://www.topcoder.com/thrive/articles/range-operations-lazy-propagation#:~:text=Lazy%20propagation%20is%20a%20range,will%20avoid%20the%20repeated%20sharing.

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // clear lazy in each testcase

    int n = 10;
    build(1, 0, n - 1);

    update(1, 0, n - 1, 1, 7, 5);
    update(1, 0, n - 1, 2, 4, -3);

    return 0;
}