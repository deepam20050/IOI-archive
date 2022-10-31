#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int arr[N];
int sz[N];
int p[N];
bool bad[N];
int n;
int m;

inline int find_set (int x) {
	return p[x] == x ? x : p[x] = find_set(p[x]);
}

inline void join (int x, int y) {
	if (sz[x] < sz[y]) {
		swap(x, y);
	}
	sz[x] += sz[y];
	p[y] = x;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", arr + i);
		p[i] = i;
		sz[i] = 1;
	}
	while (m--) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			int x, y;
			scanf("%d %d", &x, &y);
			arr[x] = y;
		} else if (op == 2) {
			int x, y;
			scanf("%d %d", &x, &y);
			int prx = find_set(x);
			int pry = find_set(y);
			if (prx == pry) {
				bad[prx] = 1;
			} else {
				join(prx, pry);
			}
		} else {
			int x, y, v;
			scanf("%d %d %d", &x, &y, &v);
			int prx = find_set(x);
			int pry = find_set(y);
			if (prx != pry) {
				puts("0");
			} else {
				if (bad[prx]) {
					puts("0");
				} else {
					long long a = arr[x] * v;
					long long b = arr[y];
					long long d = __gcd(a, b);
					a /= d;
					b /= d;
					printf("%lld/%lld\n", a, b);
				}
			}
		}
	}
	return 0;
}