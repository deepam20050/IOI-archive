// http://codeforces.com/contest/459/problem/D

#include <bits/stdc++.h>

using namespace std;

#define mygc(c) (c)=getchar()
#define mypc(c) putchar(c)

void ww(long long x, char c){int s=0,m=0;char f[10];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void sc(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}

const int N = 1e6 + 1;

vector <int> t[4 * N];
int arr[N];
int varr[N];
unordered_map <int, int> cnt1, cnt2;
int n;

void build (int nk, int l, int r) {
  for (int i = l; i <= r; ++i) {
    t[nk].emplace_back(arr[i]);
  }
  if (l == r) {
    return;
  }
  sort(t[nk].begin(), t[nk].end());
  int m = l + r >> 1;
  build(nk << 1, l, m);
  build(nk << 1 | 1, m + 1, r);
}

int query (int nk, int l, int r, int x, int y, int k) {
  if (x > y) {
    return 0;
  }
  if (x <= l && r <= y) {
    return lower_bound(t[nk].begin(), t[nk].end(), k) - t[nk].begin();
  }
  int m = l + r >> 1;
  int ans = 0;
  if (x <= m) {
    ans += query(nk << 1, l, m, x, y, k);
  }
  if (y > m) {
    ans += query(nk << 1 | 1, m + 1, r, x, y, k);
  }
  return ans;
}

int main() {
  sc(&n);
  for (int i = 0; i < n; ++i) {
    sc(&varr[i]);
  }
  for (int i = n - 1; i >= 0; --i) {
    ++cnt1[varr[i]];
    arr[i] = cnt1[varr[i]];
  }
  build(1, 0, n - 1);
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    ++cnt2[varr[i]];
    ans += query(1, 0, n - 1, i + 1, n - 1, cnt2[varr[i]]);
  }
  ww(ans, '\n');
  return 0;
}