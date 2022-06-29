const int N = 100001;
const int LG = 1 + __lg(N);
auto dist = vector(N + 1, INT_MAX);
auto LCA = vector(N + 1, vector(LG + 1, -1));
vector<vector<int>> adj;

void dfs(int s, int p) {
    LCA[s][0] = p;
    for (auto i : adj[s]) {
        if (dist[i] == INT_MAX) {
            dist[i] = 1 + dist[s];
            dfs(i, s);
        }
    }
}

void preprocess(int s) {
    dist[s] = 0;
    dfs(s, -1);
    for (int i = 1; i <= LG; ++i) {
        for (int j = 0; j <= N; ++j) {
            int p = LCA[j][i - 1];
            if (p == -1) continue;
            LCA[j][i] = LCA[p][i - 1];
        }
    }
}

int get_lca(int u, int v) {
    if (dist[u] > dist[v])
        swap(u, v);

    int dif = dist[v] - dist[u];
    while (dif > 0) {
        int lg = __lg(dif);
        v = LCA[v][lg];
        dif -= (1 << lg);
    }
    if (u == v)
        return u;

    for (int i = LG; i >= 0; --i) {
        if (LCA[u][i] == -1 || LCA[u][i] == LCA[v][i])
            continue;
        u = LCA[u][i];
        v = LCA[v][i];
    }
    return LCA[u][0];
}