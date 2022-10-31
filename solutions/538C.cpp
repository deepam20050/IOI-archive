// http://codeforces.com/problemset/problem/538/C
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int d[N], h[N];

int abso(int x) {
	return x < 0 ? -x : x;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", d + i, h + i);
	}
	int ans = max(h[0] + d[0] - 1, n - d[m - 1] + h[m - 1]);
	for (int i = 0; i < m - 1; ++i) {
		if (abso(h[i] - h[i + 1]) > d[i + 1] - d[i]) {
			return !printf("IMPOSSIBLE");
		} else {
			ans = max(ans, max(h[i], h[i + 1]) + (d[i + 1] - d[i] - abso(h[i + 1] - h[i])) / 2); 
		}
	}
	printf("%d\n", ans);
  return 0;
}