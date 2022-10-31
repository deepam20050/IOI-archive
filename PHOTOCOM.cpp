#include <bits/stdc++.h>

using namespace std;

template <typename T>
inline T gcd (T a, T b) {
  T c;
  while (b) {
    c = b;
    b = a % b;
    a = c;
  }
  return a;
}

inline long long lcm (long long a, long long b) {
  return a * b / gcd(a, b);
}

inline void init () {
  for (int i = 0; i < N; ++i) {
    arr1[i].clear();
    arr2[i].clear();
  }
}

int main() {
  scanf("%d", &tc);
  while (tc--) {
    scanf("%lld %lld", &h1, &w1);
    init();
    scanf("%s", str);
    for (int i = 0; i < h1 * w1; ++i) {
      arr1[i / h1] += str[i]; 
    }
    scanf("%lld %lld", &h2, &w2);
    scanf("%s", str);
    long long newh = lcm(h1, h2), neww = lcm(w1, w2);
    long long dh1 = newh / h1, dw1 = neww / w1;
    long long dh2 = newh / h2, dw2 = neww / w2;
    for (int i = 0; i < h2 * w2; ++i) {
      arr2[i / h2] += str[i];
    }
    long long ans = 0;
    for (int i = 0; i < h2; ++i) {
      for (int j = 0; j < w2; ++j) {
        long long x = j * dw2, y = i * dh2;
        int io = x / dh1, jo = y / dw2;
        if (arr1[io][jo] == arr2[i][j]) {
          
        }
        y += dh2 - 1;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}