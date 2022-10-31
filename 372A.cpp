// http://codeforces.com/problemset/problem/372/A
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int a[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	sort(a, a + n);
	int cnt = n, j = n / 2 - 1;
	for (int i = n - 1; i >= 0; --i) {
		for (; j >= 0; --j) {
			if (a[j] * 2 <= a[i]) {
				--j;
				--cnt;
				break;
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}