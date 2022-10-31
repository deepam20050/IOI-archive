// https://www.codechef.com/problems/QCHEF

#include <bits/stdc++.h>

#define mygc(c) (c)=getchar()
#define mypc(c) putchar(c)

void writeInt(int x, char c){int s=0,m=0;char f[10];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void sc(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}

using namespace std;

const int N = 100010;
const int SQN = 100;

int arr[N];
int best[1001][1001];
int lft[N];
vector <int> pos[N];

int n;
int m;
int q;
int blocks;

int main() {
  sc(&n);
  sc(&m);
  sc(&q);
  for (int i = 0; i < n; ++i) {
    sc(&arr[i]);
    pos[arr[i]].emplace_back(i);
  }
  blocks = n / SQN;
  for (int i = 0; i < n; i += SQN) {
    memset(lft, -1, sizeof lft);
    int mx = 0;
    int blck = i / SQN;
    for (int j = i; j < n; ++j) {
      if (j % SQN == 0) {
        best[blck][j / SQN] = mx;
      }
      if (lft[arr[j]] == -1) {
        lft[arr[j]] = j;
      }
      mx = max(mx, j - lft[arr[j]]);
    }
    best[blck][blocks] = mx;
  }
  while (q--) {
    int l, r;
    sc(&l);
    sc(&r);
    --l;
    int rgt_end = (l + SQN - 1) / SQN * SQN;
    int lft_end = r / SQN * SQN;
    int ans = best[rgt_end / SQN][lft_end / SQN];
    for (int i = l; i < rgt_end; ++i) {
      int idx = lower_bound(pos[arr[i]].begin(), pos[arr[i]].end(), r) - pos[arr[i]].begin() - 1;
      if (idx < 0) {
        continue;
      }
      ans = max(ans, pos[arr[i]][idx] - i);
    }
    for (int i = lft_end; i < r; ++i) {
      int idx = lower_bound(pos[arr[i]].begin(), pos[arr[i]].end(), l) - pos[arr[i]].begin();
      if (idx == pos[arr[i]].size()) {
        continue;
      }
      ans = max(ans, i - pos[arr[i]][idx]);
    }
    writeInt(ans, '\n');
  }
  return 0;
}