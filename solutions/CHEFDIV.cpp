// https://www.codechef.com/problems/CHEFDIV
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e6 + 1, M = 1e5 + 1;
 
bool p[N];
vector <int> g[M];
 
long long l, r, ans;
 
long long getidx(long long i) {
	return l % i ? l / i + 1 : l / i;
}
 
void sieve() {
	p[0] = p[1] = 1;
	for (int i = 2; i * i < N; ++i) {
		if (!p[i]) {
			for (int j = i + i; j < N; j += i) {
				p[j] = 1;
			}
		}
	}
	for (int i = 2; i < N; ++i) {
		if (!p[i]) {
			for (long long j = getidx(i) * i * 1LL; j <= r; j += i) {
				g[j - l].emplace_back(i);
			}
		}
	}
}
 
void solve(long long x) {
	priority_queue <int> pq;
	int add = 1;
	for (int d: g[x - l]) {
		int cnt = 0;
		while (x % d == 0) {
			x /= d;
			++cnt;
		}
		add *= cnt + 1;
		if (cnt) {
			pq.push(cnt);
		}
	}
	if (x > 1) {
		pq.push(1);
		add *= 2;
	}
	ans += add - 1;
	while (!pq.empty()) {
		int z = pq.top();
		pq.pop();
		add /= z + 1;
		add *= z;
		if (z > 1) {
			pq.push(z - 1);
		}
		ans += add;
	}
}
 
int main() {
	scanf("%lld %lld", &l, &r);
	sieve();
	for (long long i = l; i <= r; ++i) {
		solve(i);
	}
	printf("%lld\n", ans);
	return 0;
} 