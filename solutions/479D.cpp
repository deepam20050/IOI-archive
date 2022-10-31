// http://codeforces.com/problemset/problem/479/D
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

long a[N];

unordered_map <long, int> forx, fory;
vector <long> v;

int main() {
	int n, l, x, y;
	scanf("%d %d %d %d", &n ,&l, &x, &y);
	for (int i = 0; i < n; ++i) {
		scanf("%ld", a + i);
	}
	bool f1 = 0, f2 = 0;
	for (int i = 0; i < n; ++i) {
		long r1 = a[i] - x, r2 = a[i] - y, r3 = a[i] + x, r4 = a[i] + y;
		if (binary_search(a, a + n, r1) || binary_search(a, a + n, r3)) {
			f1 = 1;
		}
		if (binary_search(a, a + n, r2) || binary_search(a, a + n, r4)) {
			f2 = 1;
		}
	}
	if (f1 && f2) {
		return !printf("0");
	}
	for (int i = 0; i < n; ++i) {
		if (a[i] - x >= 0) {
			if (forx[a[i] - x] == 0) {
				++forx[a[i] - x];
			}
		}
		if (a[i] + x <= l) {
			if (forx[a[i] + x] == 0) {
				++forx[a[i] + x];
			}
		}
		if (a[i] - y >= 0) {
			if (fory[a[i] - y] == 0) {
				++fory[a[i] - y];
			}
		}
		if (a[i] + y <= l) {
			if (fory[a[i] + y] == 0) {
				++fory[a[i] + y];
			}
		}
	}
	long f1x = 0, f1y = 0;
	for (const auto &e: forx) {
		f1x = e.first;
		if (fory[e.first] + e.second == 2) {
			v.emplace_back(e.first);
		}
	}
	for (const auto &e: fory) {
		if (e.second > 0) {
			f1y = e.first;
		}
	}
	if (f1 && !f2) {
		puts("1");
		printf("%ld", f1y);
	} else if (!f1 && f2) {
		puts("1");
		printf("%ld", f1x);
	} else {
		if (!v.empty()) {
			puts("1");
			printf("%ld", v[0]);
		} else {
			puts("2");
			printf("%ld %ld", f1x, f1y);
		}
	}
	return 0;
}