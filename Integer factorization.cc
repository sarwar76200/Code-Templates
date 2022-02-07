#include <bits/stdc++.h>

using namespace std;

vector<int64_t> factorization(int64_t n) {
    vector<int64_t> pf;
    while (n % 2 == 0) pf.push_back(2), n /= 2;

    for (int64_t i = 3; i * i <= n; i += 2)
        while (n % i == 0) pf.push_back(i), n /= i;

    if (n > 1) pf.push_back(n);
    return pf;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    auto facts = factorization(134);

    return 0;
}