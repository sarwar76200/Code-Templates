pair<int, int> max_sum(vector<int>& a, int n) {
    int64_t mx = LONG_MIN, mxe = 0;
    int st = 0, ed = 0, s = 0;
    for (int i = 0; i < n; ++i) {
        mxe += a[i];
        if (mx < mxe) {
            mx = mxe, st = s, ed = i;
        }
        if (mxe < 0) {
            mxe = 0, s = i + 1;
        }
    }
    return {mx, ed - st + 1};
}