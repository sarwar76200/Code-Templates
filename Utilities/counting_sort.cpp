#include <bits/stdc++.h>
using namespace std;

void counting_sort(int* A, int N) {
  int mx_e = *max_element(A, A + N);
  int* freq = new int[mx_e + 1];
  int* temp = new int[N];

  for (int i = 0; i <= mx_e; ++i) freq[i] = 0;
  for (int i = 0; i < N; ++i) ++freq[A[i]];
  for (int i = 1; i <= mx_e; ++i) freq[i] += freq[i - 1];

  for (int i = N - 1; i >= 0; --i) {
    temp[freq[A[i]] - 1] = A[i];
    --freq[A[i]];
  }

  for (int i = 0; i < N; ++i) A[i] = temp[i];

  delete[] freq;
  delete[] temp;
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

  counting_sort(A, n);

  for (int i = 0; i < n; ++i) {
    cout << A[i] << " ";
  }
  cout << '\n';


  return 0;
}