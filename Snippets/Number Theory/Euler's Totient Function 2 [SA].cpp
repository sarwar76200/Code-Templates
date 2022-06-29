vector<int> phi;
void totient(int n) {
    phi.resize(n + 1);
    phi[0] = 0, phi[1] = 1;
    for (int i = 2; i <= n; ++i) {
        phi[i] = i;
    }

    for (int i = 2; i <= n; ++i) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
}