  int BLOCK_SIZE = ceil(sqrt(n));
  vector<vector<int64_t>> blocks(BLOCK_SIZE);

  auto get_block_id = [&](int index) {
    return index / BLOCK_SIZE;
  };
  for (int i = 0; i < n; ++i) {
    int id = get_block_id(i);
    blocks[id].push_back(a[i]);
  }
  
  auto query = [&](int l, int r, int k) -> int {
    int l_id = get_block_id(l);
    int r_id = get_block_id(r);
    int ans = 0;
    for (int i = l_id + 1; i <= r_id - 1; ++i) {
      ans += int(lower_bound(blocks[i].begin(), blocks[i].end(), k) - blocks[i].begin());
    }
    for (int i = l; i <= (l_id + 1) * BLOCK_SIZE - 1 && i <= r; ++i) {
      ans += a[i] < k;
    }
    if (l_id == r_id) return ans;
    for (int i = r; i >= r_id * BLOCK_SIZE && i >= l; --i) {
      ans += a[i] < k;
    }
    return ans;
  };