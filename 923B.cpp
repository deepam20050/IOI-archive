#include <bits/stdc++.h>

using namespace std;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", arr + i);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", t + i);
    prf[i] = prf[i - 1] + t[i];
  }
  for (int i = 1; i <= n; ++i) {
    
  }
  return 0;
}