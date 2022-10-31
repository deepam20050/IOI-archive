// http://www.spoj.com/problems/ADOMINO/
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;

long ar[N];

int n, d;

bool F(long x) {
	long lpos = ar[0];
	for (int i = 1, c = 1; i < n; ++i) {
		if (ar[i] - lpos >= x) {
			++c;
			if (c == d) {
				return 1;
			}
			lpos = ar[i];
		}
	}
	return 0;
}

long binS() {
	long l = 0, r = 10000000000;
	while (r - l > 1) {
		long x = l + r >> 1;
		if (F(x)) {
			l = x;
		} else {
			r = x;
		}
	}
	return l;
}

int main() {
	int t;
	scanf("%d",&t);
	while (t--) {
		scanf("%d %d", &n, &d);
		for (int i = 0; i < n; ++i) {
			scanf("%ld", ar + i);
		}
		sort(ar, ar + n);
		printf("%ld\n",binS());
	}

	return 0;
}