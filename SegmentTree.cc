#include <bits/stdc++.h>

using namespace std;

const int MX_N = 100001;
int a[MX_N], tree[4 * MX_N];

// 0-based indexing
void build(int node, int tL, int tR) {
    if (tL == tR) {
        tree[node] = a[tL];
        return;
    }
    int mid = (tL + tR) / 2;
    int left = 2 * node, right = 2 * node + 1;
    build(left, tL, mid);
    build(right, mid + 1, tR);
    tree[node] = min(tree[left], tree[right]);
}

void update(int node, int tL, int tR, int i, int v) {
    if (tL >= i && tR <= i) {
        tree[node] = v;
        return;
    }
    if (tR < i || tL > i) return;

    int mid = (tL + tR) / 2;
    int left = 2 * node, right = 2 * node + 1;
    update(left, tL, mid, i, v);
    update(right, mid + 1, tR, i, v);
    tree[node] = min(tree[left], tree[right]);
}

int query(int node, int tL, int tR, int qL, int qR) {
    if (tL >= qL && tR <= qR) {
        return tree[node];
    }
    if (tR < qL || tL > qR) {
        return INT_MAX;
    }
    int mid = (tL + tR) / 2;
    int QL = query(2 * node, tL, mid, qL, qR);
    int QR = query(2 * node + 1, mid + 1, tR, qL, qR);
    return min(QL, QR);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    build(1, 0, MX_N - 1);


    return 0;
}