// http://codeforces.com/contest/671/problem/A

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pi = pair <double, int>;

const int N = 100010;

double dist(ll x, ll y) {
	return sqrt(x * x + y * y);
}

priority_queue <pi, vector <pi>, greater <pi>> pq;
long long x[N], y[N];
double bin[N], a[N], b[N];

int main() {
	int ax, ay, bx, by, tx, ty;
	scanf("%d %d %d %d %d %d", &ax, &ay, &bx, &by, &tx, &ty);
	int n;
	scanf("%d", &n);
	double sum = 0.0;
	for (int i = 0; i < n; ++i) {
		scanf("%lld %lld", x + i, y + i);
		bin[i] = dist(x[i] - tx, y[i]- ty);
		a[i] = dist(x[i] - ax, y[i] - ay);
		b[i] = dist(x[i] - bx, y[i] - by);
		sum += bin[i];
		pq.push({a[i] - bin[i], i});
	}
	if (n == 1) {
		return !printf("%.9f", min(a[0], b[0]) + sum + sum - bin[0]);
	}
	double ans = 1e15;
	for (int i = 0; i < n; ++i) {
		pi pp = pq.top();
		if (pp.second == i) {
			pq.pop();
			pi temp = pq.top();
			ans = min(ans, b[i] + sum + sum - bin[i] + temp.first);
			pq.push(pp);
		} else {
			ans = min(ans, b[i] + sum + sum - bin[i] + pp.first);
		}
	}
	for (int i = 0; i < n; ++i) {
		ans = min(ans, b[i] + sum + sum - bin[i]);
	}
	for (int i = 0; i < n; ++i) {
		ans = min(ans, a[i] + sum + sum - bin[i]);
	}
	printf("%.12f", ans);
	return 0;
}