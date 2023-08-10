const int N = 10001;
bool visited[N];
vector<int> seq, comps;

void dfs(vector<vector<int>>& adj, int u, bool ts = false) {
    visited[u] = true;
    if (!ts) comps.push_back(u);
    for (auto v : adj[u]) {
        if (!visited[v]) {
            dfs(adj, v, ts);
        }
    }
    if (ts) seq.push_back(u);
}


void print() {
    for (auto i : comps) cout << i << " ";
    cout << '\n';
    comps.clear();
}

void kosaraju_scc(vector<vector<int>>& adj, vector<vector<int>>& adj_t, int n) {
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) dfs(adj, i, true);
    }
    reverse(seq.begin(), seq.end());
    memset(visited, false, sizeof visited);

    for (auto i : seq) {
        if (!visited[i]) {
            dfs(adj_t, i);
            print();
        }
    }
}