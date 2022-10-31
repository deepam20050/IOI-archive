// http://codeforces.com/problemset/problem/349/B
// AC

#include <bits/stdc++.h>

using namespace std;

int ar[10];

int main() {
	int v, mini = 1e9;
	scanf("%d",&v);

	for (int i = 1; i <= 9; ++i) {
		scanf("%d", ar + i);
		if (ar[i] <= mini) {
			mini = ar[i];
		}
	}

	int len = v / mini;
	if (!len) {
		puts("-1");
		return 0;
	}

	while (len) {
		for (int i = 9; i >= 1; --i) {
			if (ar[i] <= v && (v - ar[i]) / mini == len - 1) {
				printf("%d",i);
				v -= ar[i];
				--len;
				break;
			}
		}
	}

	return 0;
}