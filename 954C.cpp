// http://codeforces.com/contest/954/problem/C

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1;

int arr[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", arr + i);
  }
  int x = 1e9;
  int y = 1e9;
  for (int i = 1; i < n; ++i) {
    if (arr[i] == arr[i - 1]) {
      return puts("NO"), 0;
    }
    int val = abs(arr[i] - arr[i - 1]);
    if (y == 1e9 && val != 1) {
      y = val;
    } else if (val != 1 && val != y) {
      puts("NO");
      return 0;
    }
  }
  for (int i = 1; i < n; ++i) {
    if (abs(arr[i] - arr[i - 1]) == 1 && ((arr[i] - 1) / y != (arr[i - 1] - 1) / y)) {
      return puts("NO"), 0;
    } 
  }
  printf("YES\n%d %d\n", x, y);
  return 0;
}