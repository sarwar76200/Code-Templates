const int N = 10001;
vector<int> adj[N];
bool visited[N];
int tin[N], low[N];

void dfs(vector<int>& ap, int& t, int u, int p = -1) {
    visited[u] = true;
    tin[u] = low[u] = ++t;
    int children = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (visited[v]) {
            low[u] = min(low[u], tin[v]);
            continue;
        }
        dfs(ap, t, v, u);
        low[u] = min(low[u], low[v]);
        if (tin[u] <= low[v] && p != -1) {
            ap.push_back(u);
        }
        ++children;
    }
    if (p == -1 && children > 1) {
        ap.push_back(u);
    }
}
vector<int> get_ap(int n) {
    vector<int> ap;
    int timer = -1;
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(ap, timer, i);
    }
    return ap;
}