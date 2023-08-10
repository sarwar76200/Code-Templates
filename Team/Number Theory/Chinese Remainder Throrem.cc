int64_t crt(vector<int> nums, vector<int> rems) {

    __int128_t prod = 1;

    int n = nums.size();

    for (int i = 0; i < n; ++i)
        prod *= nums[i];

    int res = 0;

    for (int i = 0; i < n; ++i) {
        __int128_t pp = prod / nums[i];
        res += rems[i] * invModE<__int128_t>(pp, nums[i]) * pp;
    }

    return res % prod;
}
