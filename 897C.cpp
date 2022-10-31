// http://codeforces.com/contest/897/problem/C

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const long long oo = 1LL << 61;

const string a = "What are you doing at the end of the world? Are you busy? Will you save us?";
const string b = "What are you doing while sending \"";
const string c = "\"? Are you busy? Will you send \"";
const string d = "\"?";

long long size[N];

char get(int who, long long where) {
  if (size[who] <= where) {
    return '.';
  }
  if (!who) {
    return a[where];
  }
  if (where < b.size()) {
    return b[where];
  }
  where -= b.size();
  if (where < size[who - 1]) {
    return get(who - 1, where);
  }
  where -= size[who - 1];
  if (where < c.size()) {
    return c[where];
  }
  where -= c.size();
  if (where < size[who - 1]) {
    return get(who - 1, where);
  }
  where -= size[who - 1];
  if (where < d.size()) {
    return d[where];
  }
}

int main() {
  size[0] = a.size();
  for (int i = 1; i < N; ++i) {
    size[i] = min(oo, (long long)((size[i - 1] << 1LL) + b.size() + c.size() + d.size()));
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    long long who, where;
    scanf("%lld %lld", &who, &where);
    printf("%c", get(who, where - 1));
  }
  return 0;
}