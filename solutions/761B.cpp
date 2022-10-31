// http://codeforces.com/contest/761/problem/B

#include "bits/stdc++.h"

using namespace std;

const int N = 123;

int a[N], b[N];

int n, l;

bool check() {
	for (int i = 0; i < n; ++i) {
		if (a[i] != b[i]) {
			return 0;
		}
	}
	return 1;
}

void shift() {
	for (int i = 0; i < n; ++i) {
		--a[i];
	}
	if (a[0] == -1) {
		for (int i = 1; i < n; ++i) {
			a[i - 1] = a[i];
		}
		a[n - 1] = l - 1;
	}
}

int main() {
	scanf("%d %d", &n, &l);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", b + i);
	}
	for (int i = 0; i < l; ++i) {
		if (check()) {
			return 0*puts("YES");
		}
		shift();
	}
	puts("NO");
	return 0;
}