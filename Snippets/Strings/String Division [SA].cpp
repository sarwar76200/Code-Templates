int MOD(string s, int n) {
    int rem = 0;
    for (char i : s) {
        int dig = i - '0';
        rem = (rem * 10) + dig;
        rem %= n;
    }
    return rem;
}