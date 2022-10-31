#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;

int arr[N];

int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << '\n';
    return 0;
  } else if (n == 2) {
    puts("-1");
    return 0;
  }
  arr[1] = 2;
  arr[2] = n;
  int used = n - 2;
  for (int i = 2; used; --used) {
    arr[arr[i]] = n - i + 1;
    i = arr[i];
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d ", arr[i]);
  }
  return 0;
}