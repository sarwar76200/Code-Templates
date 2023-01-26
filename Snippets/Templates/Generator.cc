mt19937 rng;

int get(int l, int r) {
    return l + rng() % (r - l + 1);
}

int main() {
    rng.seed(chrono::steady_clock::now().time_since_epoch().count());
}