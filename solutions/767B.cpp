// On hold …

#include "bits/stdc++.h"

using namespace std;

const int N = 100010;
const long long oo = 1e18;

long long a[N];

int main() {
	for (int i = 0; i < N; ++i) {
		a[i] = oo;
	}
	long long ts, tf, t;
	scanf("%lld %lld %lld", &ts, &tf, &t);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", a + i);
	}
	if (ts < a[0]) {
		return !printf("%lld", ts);
	}
	long long add = ts;
	for (int i = 0; i < n; ++i) {
		long long temp = max(add, a[i]) + t;
		if (i + 1 < n && a[i + 1] > temp) {
			return !printf("%lld", temp);
		} 
		add = temp;
	}
	if (add + t <= tf) {
		return !printf("%lld", add);
	}
	long long wait = oo;
	long long tt = oo;
	add = ts;
	for (int i = 0; i < n; ++i) {
		long long temp = max(add, a[i]) + t;
		if (i > 0 && a[i - 1] != a[i]) {
			wait = temp - a[i - 1];
			tt = a[i - 1];
			break;
		}	
		add = temp;
	}
 	add = max(ts, a[0]) + t;
	long long wait1 = oo;
	long long tt1 = oo;
	for (int i = 1; i < n; ++i) {
		if (a[i] - a[i - 1] > t) {
			tt1 = a[i - 1] + t;
			wait1 = add - a[i - 1] - t;
			break;
		}
		add = max(add, a[i]) + t;
	}
	if (wait > wait1) {
		tt = tt1;
		wait = wait1;
	}
	if (ts - a[0] + 1 < wait) {
		tt = a[0] - 1;
	}
	printf("%lld", tt);
	return 0;
}