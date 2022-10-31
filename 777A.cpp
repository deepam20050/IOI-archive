// http://codeforces.com/contest/777/problem/A
// AC

#include <bits/stdc++.h>

using namespace std;

long ceilit(int val) {
  return val % 3 == 0 ? val / 3 : val / 3  + 1;
}

long getval(int a, long n) {
  return a + (n - 1) * 3;
}

int main() {
  long n;
  scanf("%ld", &n);
  int x;
  scanf("%d", &x);
  if (n == 1) {
    if (x == 2) {
      puts("2");
    } else if (x == 0){
      puts("1");
    } else if (x == 1) {
      puts("0");
    }
    return 0;
  }
  int a = 0, d = 3;
  {
    a = 1;
    int idx = getval(a, ceilit(n - a + d));
    if (idx == n && x == 1) {
      puts("0");
      return 0;
    } else if (idx != n && (idx & 1) && x == 0) {
      puts("0");
      return 0;
    } else if (idx != n && (idx % 2 == 0) && x == 2) {
      puts("0");
      return 0;
    } 
  } 
  {
    a = 0;
    int idx = getval(a, ceilit(n - a + d));
    if (idx == n && x == 1) {
      puts("1");
      return 0;
    } else if (idx != n && (idx & 1) && x == 0) {
      puts("1");
      return 0;
    } else if (idx != n && (idx % 2 == 0) && x == 2) {
      puts("1");
      return 0;
    }
  }
  {
    a = 2;
    int idx = getval(a, ceilit(n - a + d));
    if (idx == n && x == 1) {
      puts("2");
    } else if (idx != n && (idx & 1) && x == 0) {
      puts("2");
    } else if (idx != n && (idx % 2 == 0) && x == 2) {
      puts("2");
    }
  }
  return 0;
}

