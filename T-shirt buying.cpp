// http://codeforces.com/contest/799/problem/B
// AC

#include <bits/stdc++.h>

using namespace std;

struct d {
	long p;
	int a, b;
	bool operator<(const d &kkk) const {
		return p < kkk.p;
	}
};

const int N = 2e5 + 10;

d ar[N];
vector < queue <int> > v(4);
long ans[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%ld", &ar[i].p);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &ar[i].a);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &ar[i].b);
	}
	sort(ar, ar + n);
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int x;
		cin >> x;
		v[x].push(i);
		ans[i] = -1;
	}
	for (int i = 0; i < n; ++i) {
		int c1 = ar[i].a, c2 = ar[i].b;
		bool f1 = v[c1].empty(), f2 = v[c2].empty();
		if (c1 == c2) {
			if (!f1) {
				ans[v[c1].front()] = ar[i].p;
				v[c1].pop();
			}
		}
		if (!f1 && !f2) {
			if (v[c1].front() == v[c2].front()) {
				ans[v[c1].front()] = ar[i].p;
				v[c1].pop();
				v[c2].pop();
			} else if (v[c1].front() < v[c2].front()) {
				ans[v[c1].front()] = ar[i].p;
				v[c1].pop();
			} else if (v[c2].front() < v[c1].front()) {
				ans[v[c2].front()] = ar[i].p;
				v[c2].pop();
			}
		} else if (!f1 && f2) {
			ans[v[c1].front()] = ar[i].p;
			v[c1].pop();
		} else if (f1 && !f2) {
			ans[v[c2].front()] = ar[i].p;
			v[c2].pop();
		}
	}
	for (int i = 0; i < m; ++i) {
		printf("%ld ", ans[i]);
	}
	return 0;
}