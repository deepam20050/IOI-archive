// https://dmoj.ca/problem/ccc14s1

#include "bits/stdc++.h"

using namespace std;

bool a[110];

int main() {
	int k;
	scanf("%d", &k);
	int m;
	scanf("%d", &m);
	while (m--) {
		int x;
		scanf("%d", &x);
		int cnt = 1;
		for (int i = 1; i <= k; ++i) {
			if (!a[i]) {
				if (cnt % x == 0) {
					a[i] = 1;
				}
				++cnt;
			}
		}
	}
	for (int i = 1; i <= k; ++i) {
		if (!a[i]) {
			printf("%d\n", i);
		}
	}
	return 0;
}