struct chash {
    const uint64_t C = uint64_t(2e18 * numbers::pi) + 71;
    const unsigned int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
 
    uint64_t operator()(int64_t x) const {
        return __builtin_bswap64((x ^ RANDOM) * C);
    }
};