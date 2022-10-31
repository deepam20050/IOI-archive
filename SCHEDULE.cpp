// https://www.codechef.com/problems/SCHEDULE

#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

bool a[N];
vector <int> sz;

int n, k;

bool F(int x) {
	int ans = 0;
	int s = 1;
	for (int i = 1; i < n; ++i) {
		if (a[i] == a[i - 1]) {
			++s;
		} else {
			ans += s / (x + 1);
			s = 1;
		}
	}
	ans += s / (x + 1);
	return ans <= k;
}

bool c1() {
	int a1 = 0, a2 = 0, v1 = 0, v2 = 1;
	for (int i = 0; i < n; ++i, v1 ^= 1, v2 ^= 1) {
		if (a[i] != v1) {
			++a1;
		} 
		if (a[i] != v2) {
			++a2;
		}
	}
	return min(a1, a2) <= k;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &k);
		sz.clear();
		for (int i = 0; i < n; ++i) {
			char ch;
			cin >> ch;
			a[i] = ch - '0';
		}
		for (int i = 1, s = 1; i <= n; ++i) {
			if (i == n) {
				sz.emplace_back(s);
			} else if (a[i] == a[i - 1]) {
				++s;
			} else {
				sz.emplace_back(s);
				s = 1;
			}
		}
		if (c1()) {
			puts("1");
			continue;
		}
		int ans = sz[0];
		int l = 2, r = n;
		while (l < r) {
			int m = (l + r) >> 1;
			if (F(m)) {
				r = m;
			} else {
				l = m + 1;
			}
		}
		printf("%d\n", l);
	}
	return 0;
}