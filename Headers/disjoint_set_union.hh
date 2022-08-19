#include <iostream>
#include <vector>

using namespace std;

struct DisjointSet {
    vector<int32_t> parent, comp_size;
    size_t components, nodes;

    explicit DisjointSet(size_t size) {
        DisjointSet::nodes = size;
        DisjointSet::components = 0;
        parent.resize(nodes, -1);
        comp_size.resize(nodes, -1);
    }

    void make_set(int32_t u) {
        parent[u] = u;
        comp_size[u] = 1;
        ++components;
    }

    void make_set() {
        for (int i = 0; i < nodes; ++i) {
            make_set(i);
        }
    }

    int32_t get_size(int32_t u) {
        return comp_size[find(u)];
    }

    size_t get_components_count() const {
        return components;
    }

    int32_t find(int32_t u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    void unite(int32_t u, int32_t v) {
        u = find(u), v = find(v);
        if (u != v) {
            if (comp_size[u] < comp_size[v]) swap(u, v);
            parent[v] = u;
            comp_size[u] += comp_size[v];
            --components;
        }
    }
};
