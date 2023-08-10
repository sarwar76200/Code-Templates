int egcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int x1, y1;
    int gcd = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return gcd;
}

int invModE(int a, int m) {
    // Modular multiplicative inverse using extended euclidean algorithm
    // a and m are coprime
    int x, y, g = egcd(a, m, x, y);
    if (x < 0)
        x = (x + m) % m;

    return x;
}