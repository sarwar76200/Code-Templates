const int N = 105, R = 85;
int64_t NCR[N][R];

void genNCR() {
    for (int i = 0; i < N; ++i) {
        NCR[i][0] = 1;
        if (i < R) NCR[i][i] = 1;
    }
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j <= i; ++j) {
            NCR[i][j] = NCR[i - 1][j - 1] + NCR[i - 1][j];
        }
    }
}