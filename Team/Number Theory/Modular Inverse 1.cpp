int invModF(int a, int m) {
    // Modular multiplicative inverse using fermat's little theorem
    // m is a prime number
    return bin_expo(a, m - 2, m);
}