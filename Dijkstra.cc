#include <bits/stdc++.h>

using namespace std;

const int N = 100001;
struct Node {
    int vertex, weight;
};

int dist[N], parent[N];
bool vis[N];
vector<Node> adj[N];

void init() {
    for (int i = 0; i < N; ++i) {
        dist[i] = INT_MAX, parent[i] = -1, vis[i] = false;
    }
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