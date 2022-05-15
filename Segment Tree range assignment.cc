#include <bits/stdc++.h>

using namespace std;

const int N = 100001;
int a[N], tree[4 * N], lazy[4 * N];

void propagate(int node, int tL, int tR, int v) {
    tree[node] = (tR - tL + 1) * v;
    if (tL != tR) {
        int left = 2 * node, right = 2 * node + 1;
        lazy[left] = v;
        lazy[right] = v;
    }
}

void build(int node, int tL, int tR) {
    if (tL == tR) {
        tree[node] = a[tL];
        return;
    }
    int mid = (tL + tR) / 2;
    int left = 2 * node, right = 2 * node + 1;
    build(left, tL, mid);
    build(right, mid + 1, tR);
    tree[node] = tree[left] + tree[right];
}

int query(int node, int tL, int tR, int qL, int qR) {
    if (tL > tR) return 0;

    if (lazy[node] != -1) {
        propagate(node, tL, tR, lazy[node]);
        lazy[node] = -1;
    }
    if (tR < qL || tL > qR)
        return 0;

    if (tL >= qL && tR <= qR) {
        return tree[node];
    }

    int mid = (tL + tR) / 2;
    int left = 2 * node, right = 2 * node + 1;
    return query(left, tL, mid, qL, qR) + query(right, mid + 1, tR, qL, qR);
}

void update(int node, int tL, int tR, int qL, int qR, int v) {
    if (tL > tR)
        return;

    if (lazy[node] != -1) {
        propagate(node, tL, tR, lazy[node]);
        lazy[node] = -1;
    }
    if (tR < qL || tL > qR)
        return;
    if (tL >= qL && tR <= qR) {
        propagate(node, tL, tR, v);
        return;
    }

    int mid = (tL + tR) / 2;
    int left = 2 * node, right = 2 * node + 1;
    update(left, tL, mid, qL, qR, v);
    update(right, mid + 1, tR, qL, qR, v);
    tree[node] = tree[left] + tree[right];
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 10;
    build(1, 0, n - 1);

    // clear lazy in each testcase
    memset(lazy, -1, sizeof lazy);

    update(1, 0, n - 1, 1, 7, 5);
    update(1, 0, n - 1, 2, 4, -3);

    return 0;
}