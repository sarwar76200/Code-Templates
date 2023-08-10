struct Edge {
    int u, v, w;
};
int kruskal_mst(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });

    DisjointSet dsu(n + 1);
    dsu.make_set();

    int res = 0;
    for (auto [u, v, w] : edges) {
        if (dsu.find(u) == dsu.find(v)) continue;

        dsu.unite(u, v);
        res += w;
    }
    return res;
}