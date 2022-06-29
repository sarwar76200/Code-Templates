const int N = 100001;
int parent[N], comp_size[N];
int components = 0;

void make_set(int u) {
    parent[u] = u;
    comp_size[u] = 1;
    ++components;
}

int get_size(int u) {
    return comp_size[find(u)];
}

int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void unite(int u, int v) {
    u = find(u), v = find(v);
    if (u != v) {
        if (comp_size[u] < comp_size[v]) {
            swap(u, v);
        }
        parent[v] = u;
        comp_size[u] += comp_size[v];
        --components;
    }
}