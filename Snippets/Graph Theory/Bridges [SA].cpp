const int N = 100001;
vector<int> adj[N];
bool visited[N];
int tin[N], low[N];

void dfs(int u, int p, int& timer) {
    visited[u] = true;
    tin[u] = low[u] = ++timer;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (visited[v]) {
            low[u] = min(low[u], tin[v]);
        }
        else {
            dfs(v, u, timer);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u]) {
                // u-v is a bridge
            }
        }
    }
}
void find_bridges(int n) {
    int timer = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i, -1, timer);
    }
}