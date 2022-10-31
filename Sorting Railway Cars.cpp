// http://codeforces.com/problemset/problem/605/A
// AC

#include <bits/stdc++.h>

using namespace std;

int a[100010];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0, x; i < n; ++i) {
		scanf("%d", &x);
		a[x] = a[x - 1] + 1;
	}
	printf("%d\n", n - *max_element(a, a + n + 1));
	return 0;
}