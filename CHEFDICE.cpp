// https://www.codechef.com/problems/CHEFDICE

#include <bits/stdc++.h>

using namespace std;

int a[1234];

int n;

bool check(int p[]) {
	for (int i = 0; i < 6; ++i) {
		if (i == p[i] || i != p[p[i]]) {
			return 0;
		}
	}
	return 1;
}

bool match(int p[]) {
	for (int i = 1; i < n; ++i) {
		if (a[i] == a[i - 1] || p[a[i - 1]] == a[i]) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
			--a[i];
		}
		int p[] = {0, 1, 2, 3, 4, 5};
		bool ok = 0;
		do {
			if (check(p) && match(p)) {
				ok = 1;
				for (int i = 0; i < 6; ++i) {
					printf("%d ", p[i] + 1);
				}
				puts("");
				break;
			}
		} while (next_permutation(p, p + 6));
		if (!ok) {
			puts("-1");
		}
	}
	return 0;
}