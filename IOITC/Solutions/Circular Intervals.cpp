// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

long long l[N];
long long r[N];
long long where[N];
long long m;
long long n;

bool f (long long x) {
	where[0] = l[0];
	long long shift = r[0] - l[0];
	for (int i = 1; i < n; ++i) {
		long long new_pos = where[i - 1] + x;
		if (new_pos > r[i]) {
			return 0;
		} else if (new_pos < l[i]) {
			long long new_shift = l[i] - new_pos;
			long long net_shift = min(new_shift, shift);
			where[0] += net_shift;
			shift -= net_shift;
			where[i] = l[i];
			shift = min(shift, r[i] - l[i]);
		} else {
			where[i] = new_pos;
			shift = min(shift, r[i] - new_pos);
		}
	}
	if (m - where[n - 1] + where[0] < x) {
		return 0;
	}
	return 1;
}

int main() {
	scanf("%lld %d", &m, &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld %lld", l + i, r + i);
	}
	long long l = 0, r = m;
	for (int i = 0; i < 62; ++i) {
		long long x = l + r >> 1LL;
		if (f(x)) {
			l = x;
		} else {
			r = x;
		}
	}
	printf("%lld\n", l);
	return 0;
}