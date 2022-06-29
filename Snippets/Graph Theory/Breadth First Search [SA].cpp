const int N = 10001;
int dist[N], parent[N];
vector<int> adj[N];

void init() {
    memset(dist, -1, sizeof dist);
    memset(parent, -1, sizeof parent);
}
}

void bfs(int s) {
    queue<int> q;
    q.push(s);
    dist[s] = 0, parent[s] = -1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}