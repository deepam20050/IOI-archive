// http://codeforces.com/problemset/problem/625/C
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 501;

int ar[N][N];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);	
	for (int i = 1, c = 1; i <= n; ++i) {
		for (int j = 1; j < k; ++j) {
			ar[i][j] = c++;
		}
	}
	for (int i = 1, c = n * n; i <= n; ++i) {
		for (int j = n; j >= k; --j) {
			ar[i][j] = c--;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += ar[i][k];
	}
	printf("%d\n", ans);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			printf("%d ", ar[i][j]);
		}
		putchar('\n');
	}
	return 0;
}