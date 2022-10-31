// https://dmoj.ca/problem/ccc05s5
// Nice problem on Inversions :)

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int a[N];

int n;
long long cnt;

void merge(int p[], int l[], int r[], int sz) {
  int m = sz >> 1;
  int sz1 = m, sz2 = sz - m;
  for (int i = 0, j = 0; i < sz1; ++i) {
    long long curr = j;
    while (j < sz2 && r[j] < l[i]) {
      ++curr;
      ++j;
    }
    cnt += curr;
  }
  int i = 0, j = 0, k = 0;
  while (i < sz1 && j < sz2) {
    if (l[i] <= r[j]) {
      p[k++] = l[i++];
    } else {
      p[k++] = r[j++];
    }
  }
  while (i < sz1) {
    p[k++] = l[i++];
  }
  while (j < sz2) {
    p[k++] = r[j++];
  }
}

void mergesort(int p[], int sz) {
  if (sz >= 2) {
    int m = sz >> 1;
    int l[m], r[sz - m];
    for (int i = 0; i < m; ++i) {
      l[i] = p[i];
    }
    for (int i = m; i < sz; ++i) {
      r[i - m] = p[i];
    }
    mergesort(l, m);
    mergesort(r, sz - m);
    merge(p, l, r, sz);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  mergesort(a, n);
  long long szz = n;
  printf("%.2f\n", (double)(cnt + szz) / szz);
  return 0;
}