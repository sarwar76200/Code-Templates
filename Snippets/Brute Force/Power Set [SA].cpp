void power_set(vector<int>& v, int n, int i = 0) {
    if (i == n) {
        // print (v)
        return;
    }
    v.push_back(i);
    power_set(v, n, i + 1);
    v.pop_back();
    power_set(v, n, i + 1);
}