int arithmetic_nth_term(int a, int n, int d) {
    return a + (n - 1) * d;
}
int arithmetic_sum(int a, int n, int d) {
    return n * (2 * a + (n - 1) * d) / 2;
}
int geometric_nth_term(int a, int n, int r) {
    return a * pow(r, n - 1);
}
int geometric_sum(int a, int n, int r) {
    if (r == 1) return n * a;
    if (r < 1) return a * (1 - pow(r, n)) / (1 - r);
    else return a * (pow(r, n) - 1) / (r - 1);
}
int infinite_geometric_sum(int a, int r) {
    assert(r < 1);
    return a / (1 - r);
}