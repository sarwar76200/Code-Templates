const int INF = 99999999;
struct Edge {
    int u, v, w;
};

vector<int> bellman_ford(vector<Edge>& adj, int n, int m, int s) {
    vector<int> dist(n, INF);
    dist[s] = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            if (dist[adj[j].u] < INF) {
                dist[adj[j].v] = min(dist[adj[j].v], dist[adj[j].u] + adj[j].w);
            }
        }
    }
    return dist;
}