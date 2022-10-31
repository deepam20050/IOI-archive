// http://codeforces.com/problemset/problem/523/C

#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

char s[1234], t[N];

int main() {
	scanf("%s", s);
	scanf("%s", t);
	int n = strlen(s), m = strlen(t);
	int r = 0;
	int i = 0;
	bool ok = 0;
	while (r < m) {
		if (t[r] == s[i]) {
			++i;
		}
		if (i == n) {
			ok = 1;
			break;
		}
		++r;
	}
	if (!ok) {
		return !printf("0");
	}
	int l = m - 1;
	i = n - 1;
	ok = 0;
	while (l >= 0) {
		if (t[l] == s[i]) {
			--i;
		}
		if (i == -1) {
			ok = 1;
			break;
		}
		--l;
	}
	if (!ok || l - r <= 0) {
		return !printf("0");
	}
	printf("%d\n", l - r);
	return 0;
}