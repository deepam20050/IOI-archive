// AC
// For further reference on solution : https://www.iarcs.org.in/inoi/online-study-material/problems/catering-contracts-2pi-soln.php#solution

#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int N = 2510;
const int K = 100;
const long long mod = 10243;

vector <int> g[N];
long long dp[N][K];
long long tmp[K];
int n, k;

void dfs (int x, int p) {
  dp[x][0] = 1;
  dp[x][1] = 1;
  for (int to : g[x]) {
    if (to == p) {
      continue;
    }
    dfs(to, x);
    memset(tmp, 0, sizeof tmp);
    for (int i = 2; i <= k; ++i) {
      for (int j = 1; j <= i; ++j) {
        int left = i - j;
        tmp[i] += dp[x][j] * dp[to][left];
        tmp[i] %= mod;
      }
    }
    for (int i = 2; i <= k; ++i) {
      dp[x][i] = tmp[i];
    }
  }
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i < n; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  dfs(1, -1);
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += dp[i][k];
    ans %= mod;
  }
  printf("%lld", ans);
  return 0;
}