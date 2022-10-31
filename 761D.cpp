// http://codeforces.com/contest/761/problem/D

#include "bits/stdc++.h"

using namespace std;

const int N = 100010;

pair <int, int> p[N];
int a[N];
int cc[N];
int c[N];
int b[N];
vector <int> v;

int main() {
	int n, l, r;
	scanf("%d %d %d", &n, &l, &r);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", cc + i);
		p[i].first = cc[i];
		p[i].second = i;
	}
	sort(p, p + n);
	b[p[0].second] = l;
	int abtak = l - a[p[0].second];
	v.push_back(abtak);
	for (int i = 1; i < n; ++i) {
		int kk = abtak + a[p[i].second] + 1;
		if (!(l <= kk && kk <= r)) {
			kk = l;
		}
		if (binary_search(v.begin(), v.end(), kk - a[p[i].second]) || (v.back() >= kk - a[p[i].second])) {
			return !printf("-1");
		} else {
			b[p[i].second] = kk;
			v.push_back(kk - a[p[i].second]);
			abtak = kk - a[p[i].second];
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%d ", b[i]);
	}
	return 0;
}