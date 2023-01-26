int cross_product(pair<int, int>& O, pair<int, int>& A, pair<int, int>& B) {
	return (A.first - O.first) * (B.second - O.second) - (A.second - O.second) * (B.first - O.first);
}

vector<pair<int, int>> convex_hull(vector<pair<int, int>> A) {
	int n = A.size(), k = 0;
	if (n <= 3) return A;

	vector<pair<int, int>> ans(2 * n);

	sort(A.begin(), A.end());

	for (int i = 0; i < n; ++i) {
		while (k >= 2 && cross_product(ans[k - 2], ans[k - 1], A[i]) <= 0) {
			k--;
		}
		ans[k++] = A[i];
	}

	for (int i = n - 1, t = k + 1; i > 0; --i) {
		while (k >= t && cross_product(ans[k - 2], ans[k - 1], A[i - 1]) <= 0) {
			k--;
		}
		ans[k++] = A[i - 1];
	}

	ans.resize(k - 1);

	return ans;
}