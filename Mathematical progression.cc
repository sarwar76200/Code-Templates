#include <bits/stdc++.h>

using namespace std;

namespace mathematical_progression {
    template<typename type>
    type arithmetic_nth_term(type a, type n, type d) {
        return a + (n - 1) * d;
    }

    template<typename type>
    type arithmetic_sum(type a, type n, type d) {
        return n * (2 * a + (n - 1) * d) / 2;
    }

    template<typename type>
    type geometric_nth_term(type a, type n, type r) {
        return a * pow(r, n - 1);
    }

    template<typename type>
    type geometric_sum(type a, type n, type r) {
        if (r == 1) return n * a;
        if (r < 1) return a * (1 - pow(r, n)) / (1 - r);
        else return a * (pow(r, n) - 1) / (r - 1);
    }

    template<typename type>
    type infinite_geometric_sum(type a, type r) {
        assert(r < 1);
        return a / (1 - r);
    }
}

using namespace mathematical_progression;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << arithmetic_sum(1, 100, 1) << '\n';

    return 0;
}