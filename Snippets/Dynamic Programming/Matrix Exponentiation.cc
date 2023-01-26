const int nmax = 100;
const int mod = 1e9 + 7;

struct Matrix {
    int r, c;
    long long int m[nmax][nmax];

    Matrix(int _r, int _c) {
        r = _r;
        c = _c;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                m[i][j] = 0;
            }
        }
    }

    Matrix operator*(Matrix other) {
        int l = r;
        int n = c;
        int p = other.c;
        Matrix prod(l, p);

        for (int i = 0; i < l; i++) {
            for (int j = 0; j < p; j++) {
                for (int k = 0; k < n; k++) {
                    prod.m[i][j] += m[i][k] * other.m[k][j];
                    prod.m[i][j] %= mod;
                }
            }
        }

        return prod;
    }


    Matrix pow(long long int n) {
        if (n == 0) {
            Matrix I(r, c);
            for (int i = 0; i < r; i++)
                I.m[i][i] = 1;
            return I;
        }

        Matrix squared = (*this) * (*this);
        Matrix result = squared.pow(n / 2);
        if (n % 2 == 1) {
            result = result * (*this);
        }

        return result;
    }
};
