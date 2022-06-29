const int N = 10001;
bool visited[N];
vector<int> seq;

void dfs(vector<vector<int>>& adj, int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v])
            dfs(adj, v);
    }
    seq.push_back(u);
}

void topological_sort(vector<vector<int>>& adj, int nodes) {
    for (int i = 1; i <= nodes; ++i) {
        if (!visited[i]) dfs(adj, i);
    }
    reverse(seq.begin(), seq.end());
}