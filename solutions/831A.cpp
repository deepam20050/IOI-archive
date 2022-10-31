// http://codeforces.com/contest/831/problem/A

#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int a[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	int pos1 = 0, pos2 = n - 1;
	while (pos1 + 1 < n && a[pos1 + 1] > a[pos1]) {
		++pos1;
	}
	while (pos2 - 1 >= 0 && a[pos2 - 1] > a[pos2]) {
		--pos2;
	}
	for (int i = pos1; i < pos2; ++i) {
		if (a[i] != a[i + 1]) {
			return !printf("NO");
		}
	}
	puts("YES");
	return 0;
}