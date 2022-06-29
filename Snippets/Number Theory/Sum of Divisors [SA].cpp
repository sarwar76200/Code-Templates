const int N = 1e6;
int SOD[N + 1];
void generate_sod() {
    for (int i = 1; i <= N; ++i) {
        for (int j = i; j <= N; j += i) {
            SOD[j] += i;
        }
    }
}