#include <bits/stdc++.h>
using namespace std;

void merge(int* A, int L, int R) {
  int mid = (L + R) / 2;
  int merged[R - L + 1];
  int i = L, j = mid + 1, k = 0;
  for (; i <= mid && j <= R;) {
    if (A[i] < A[j]) {
      merged[k++] = A[i];
      ++i;
    } else {
      merged[k++] = A[j];
      ++j;
    }
  }
  while (i <= mid) merged[k++] = A[i], ++i;
  while (j <= R) merged[k++] = A[j], ++j;
  for (auto m : merged) A[L++] = m;
}

void merge_sort(int* A, int L, int R) {
  if (L == R) {
    return;
  }
  int mid = (L + R) / 2;
  merge_sort(A, L, mid);
  merge_sort(A, mid + 1, R);
  merge(A, L, R);
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int A[n];

  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }

  merge_sort(A, 0, n - 1);

  for (int i = 0; i < n; ++i) {
    cout << A[i] << " ";
  }
  cout << '\n';


  return 0;
}