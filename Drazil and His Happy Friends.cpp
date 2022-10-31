// http://codeforces.com/problemset/problem/515/B
// AC

#include <bits/stdc++.h>

using namespace std;

bool boys[120], girls[120];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int a;
	scanf("%d", &a);
	for (int i = 0; i < a; ++i) {
		int x;
		scanf("%d", &x);
		boys[x] = 1;
	}
	int b;
	scanf("%d", &b);
	for (int i = 0; i < b; ++i) {
		int x;
		scanf("%d", &x);
		girls[x] = 1;
	}
	for (int i = 0; i < 1000000; ++i) {
		int b = i % n, g = i % m;
		if (boys[b] || girls[g]) {
			boys[b] = girls[g] = 1;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (!boys[i]) {
			return !printf("No");
		}
	}
	for (int i = 0; i < m; ++i) {
		if (!girls[i]) {
			return !printf("No");
		}
	}
	puts("Yes");
	return 0;
}