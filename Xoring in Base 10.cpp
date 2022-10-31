// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/xoring-in-base-10/description/
// Implementation is a pain in the ass

#include <bits/stdc++.h>

using namespace std;

const int N = 44;
const int SZ = 5e5;
const int pw[10] = {1 , 10 , 100 , 1000 , 10000 , 100000 , 1000000 , 10000000 , 100000000 , 1000000000};
vector < int > v1;
vector < int > v2;
int arr[N];
int k;

inline int getdigit (long long x, int i) {
  return (x / pw[i]) % 10;
}

struct data {
  int pos = 1;
  int trie[SZ][10];
  inline void insert (long long x) {
    int node = 1;
    for (int i = 9; i >= 0; --i) {
      int d = getdigit(x, i);
      if (!trie[node][d]) {
        trie[node][d] = ++pos;
      }
      node = trie[node][d];
    }
  } 
  inline long long query (long long num) {
    int node = 1;
    long long res = 0;
    for(int i = 9 ; i >= 0 ; --i){
      res *= 10;
      int c = getdigit(num , i);
      int idx = -1;
      for(int j = 0 ; j < 10 ; ++j){
          if(!trie[node][j]){
              continue;
          }
          int val = (j + c) % 10;
          if(idx == -1 || (val > ((idx + c) % 10))){
              idx = j;
          }
      }
      res += ((idx + c) % 10);
      node = trie[node][idx];
    }
    return res;
    }
};

data sizes[N];

inline long long do_xor (long long a, long long b) {
  long long res = 0;
  for (int i = 0; i < 10; ++i) {
    int d1 = a % 10;
    int d2 = b % 10;
    res += ((d1 + d2) % 10) * pw[i];
    a /= 10;
    b /= 10;
  }
  return res;
}

long long ans = -1;
inline void solve1 () {
  int n = v1.size();
  int p = 1 << n;
  for (int mask = 1; mask < p; ++mask) {
    if (__builtin_popcount(mask) > k){
     continue;
    }
    long long num = 0;
    for (int i = 0; i < n; ++i) {
      if (mask & (1 << i)) {
        num = do_xor(num, v1[i]);
      }
    }
    int sz = __builtin_popcount(mask);
    if (sz < k) {
      sizes[sz].insert(num);
    } else if (sz == k) {
      ans = max(ans, num);
    }
  }
}

inline void solve2 () {
  int n = v2.size();
  int p = 1 << n;
  for (int mask = 1; mask < p; ++mask) {
    long long num = 0;
    for (int i = 0; i < n; ++i) {
      if (mask & (1 << i)) {
        num = do_xor(num, v2[i]);
      }
    }
    int sz = __builtin_popcount(mask);
    if (sz < k) {
      ans = max(ans, sizes[k - sz].query(num));
    } else if (sz == k) {
      ans = max(ans, num);
    }
  }
}

int main() {
  int n;
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", arr + i);
  }
  for (int i = 1; i <= n; ++i) {
    if (i <= (n >> 1)) {
      v1.emplace_back(arr[i]);
    } else {
      v2.emplace_back(arr[i]);
    }
  }
  solve1();
  solve2();
  printf("%lld\n", ans);
  return 0;
}