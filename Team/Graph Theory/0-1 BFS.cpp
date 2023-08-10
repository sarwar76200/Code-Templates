const int INF = 10000;
void bfs(vector<vector<pair<int, int>>>& adj, int n, int s) {
    vector<int> dist(n, INF);
    dist[s] = 0;
    deque<int> q;
    q.push_front(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop_front();
        for (auto edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (w == 1) {
                    q.push_back(v);
                }
                else {
                    q.push_front(v);
                }
            }
        }
    }
}