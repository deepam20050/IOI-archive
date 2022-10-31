// http://codeforces.com/contest/862/problem/C

#include <bits/stdc++.h>

using namespace std;

const int pw = 1 << 17;

int main() {
	int n, x;
	scanf("%d %d", &n, &x);
	if (n == 2 && x == 0) {
		puts("NO");
	} else if (n == 1) {
		puts("YES");
		printf("%d", x);
	} else if (n == 2) {
		puts("YES");
		printf("0 %d", x);
	} else {
		puts("YES");
		int y = 0;
		for (int i = 0; i < n - 3; ++i) {
			printf("%d ", i + 1);
			y ^= (i + 1);
		}
		if (y != x) {
			printf("0 %d %d", pw, pw ^ x ^ y);
		} else {
			printf("%d %d %d", pw, 2 * pw, pw ^ (2 * pw));
		}
	}
	return 0;
}