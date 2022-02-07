#include <bits/stdc++.h>

using namespace std;

const int MX_N = 100001;
struct Node {
    int vertex, weight;
};

int dist[MX_N], parent[MX_N];
bool vis[MX_N];
vector<Node> adj[MX_N];

void init() {
    for (int i = 0; i < MX_N; ++i) {
        dist[i] = INT_MAX, parent[i] = -1, vis[i] = false;
    }
}

void reset() {
    init();
    for (auto& i : adj)
        i.clear();
}

vector<int> path(int dst) {
    int cur = dst;
    vector<int> path;
    while (cur != -1) {
        path.push_back(cur);
        cur = parent[cur];
    }
    reverse(path.begin(), path.end());
    return path;
}

struct cmp {
    bool operator()(Node& a, Node& b) const {
        return a.weight > b.weight;
    }
};

void dijkstra(int s) {
    dist[s] = 0, vis[s] = true;

    priority_queue<Node, vector<Node>, cmp> PQ;
    PQ.push({s, 0});

    while (!PQ.empty()) {
        Node cur = PQ.top();
        PQ.pop();
        int u = cur.vertex;
        for (auto &&[v, w] : adj[u]) {
            if (!vis[v] && (dist[u] + w) < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                PQ.push({v, dist[v]});
            }
        }
        vis[u] = true;
    }
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    init();


    return 0;
}