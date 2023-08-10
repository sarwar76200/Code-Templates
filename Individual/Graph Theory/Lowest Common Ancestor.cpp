vector<int> dist;
vector<vector<int>> up;
vector<vector<int>> adj;
int lg = -1;

void dfs(int u, int p = -1) {
    up[u][0] = p;
    for (auto v : adj[u]) {
        if (dist[v] != -1) continue;
        dist[v] = 1 + dist[u];
        dfs(v, u);
    }
}

void pre_process(int root, int n) {
    assert(lg != -1);
    dist[root] = 0;
    dfs(root);
    for (int i = 1; i < lg; ++i) {
        for (int j = 1; j <= n; ++j) {// 1-based graph
            int p = up[j][i - 1];
            if (p == -1) continue;
            up[j][i] = up[p][i - 1];
        }
    }
}

int get_lca(int u, int v) {
    if (dist[u] > dist[v])
        swap(u, v);

    int dif = dist[v] - dist[u];
    while (dif > 0) {
        int lg = __lg(dif);
        v = up[v][lg];
        dif -= (1 << lg);
    }
    if (u == v)
        return u;

    for (int i = lg - 1; i >= 0; --i) {
        if (up[u][i] == up[v][i]) continue;
        u = up[u][i];
        v = up[v][i];
    }
    return up[u][0];
}

int get_kth_ancestor(int v, int k) {
    while (k > 0) {
        int lg = __lg(k);
        v = up[v][lg];
        k -= (1 << lg);
    }
    return v;
}