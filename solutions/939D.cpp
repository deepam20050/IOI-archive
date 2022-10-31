// http://codeforces.com/contest/939/problem/D

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

char s1[N];
char s2[N];
int size[26];
int p[26];
string str[26];

int n;

int find_set (int x) {
  return p[x] == x ? x : (p[x] = find_set(p[x]));
}

void join (int a, int b) {
  int x = find_set(a), y = find_set(b);
  if (x != y) {
    if (size[x] < size[y]) {
      swap(x, y);
      swap(a, b);
    }
    p[y] = x;
    size[x] += size[y];
    str[x] += b + 'a';
  }
}

int main() {
  scanf("%d", &n);
  scanf("%s", s1);
  scanf("%s", s2);
  for (int i = 0; i < 26; ++i) {
    size[i] = 1;
    p[i] = i;
  }
  for (int i = 0; i < n; ++i) {
    if (s1[i] != s2[i]) {
      join(s1[i] - 'a', s2[i] - 'a');
    }
  }
  int sz = 0;
  for (int i = 0; i < 26; ++i) {
    sz += str[i].size();
  }
  printf("%d\n", sz);
  for (int i = 0; i < 26; ++i) {
    for (char ch : str[i]) {
      printf("%c %c\n", i + 'a', ch);
    }
  }
  return 0;
}