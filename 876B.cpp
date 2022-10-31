// http://codeforces.com/problemset/problem/876/B

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int cnt[N], a[N];

int main() {
	int n, k, m;
	scanf("%d %d %d", &n, &k, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		++cnt[a[i] % m];
	}
	for (int i = 0; i < m; ++i) {
		if (cnt[i] >= k) {
			puts("Yes");
			int c = 0;
			for (int j = 0; j < n; ++j) {
				if (a[j] % m == i) {
					printf("%d ", a[j]);
					++c;
				}
				if (c == k) {
					return 0;
				}
			}
		}
	}
	puts("No");
	return 0;
}