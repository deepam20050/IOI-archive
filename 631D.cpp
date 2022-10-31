// Way too complex with hashing :(

#include <bits/stdc++.h>

using namespace std;

inline void input (int &sz, int cnt[], char ch[], int cs[], long long ccnt[[]]) {
	for (int i = 0; i < sz; ++i) {
		char ch;
		cin >> cnt[i] >> dash >> s[i]; 
	}
	int where = 0;
	for (int i = 0; i < sz; ++i) {
		if (!i) {
			cs[where] = s[i];
			ccnt[where] = cnt[i];
		} else if (s[i] == cs[where]) {
			ccnt[where] += 1LL * cnt[i];
		} else {
			++where;
			cs[where] = s[i];
			ccnt[where] = cnt[i];
		}
	}
	sz = where;
}

long long sum_geo (long long r, long long n, long long mod) {
	return mul(power(r, n) - 1LL, inv(r - 1LL, mod), mod);
}

long long geo (long long l, long long r, long long mod) {
	return sub(sum_geo(r), sum_geo(l - 1), mod);
}

inline void compute (int sz, long long cnt[], char s[]) {
	long long hsh1 = 0LL, hsh2 = 0LL;
	for (int i = 0; i < sz; ++i) {

	}
}

int main() {
	pw1[0] = 1;
	pw2[0] = 1;
	for (int i = 1; i < N; ++i) {
		pw1[i] = mul(pw1[i - 1], p1, mod1);
		pw2[i] = mul(pw2[i - 1], p2, mod2);
	}
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	input(n, cnt, ch, s1, cnt1);
	input(m, cnt, ch, s2, cnt2);
	return 0;
}