// http://codeforces.com/contest/527/problem/C
// AC

#include <bits/stdc++.h>

using namespace std;

unordered_map <int, int> mp_hor, mp_ver;

set <int> hor, ver;
multiset <int, greater <int>> mhor, mver;

int main() {
	int n, m, q;
	scanf("%d %d %d", &n, &m, &q);
	ver.insert(n);
	ver.insert(0);
	mver.insert(n);
	hor.insert(m);
	hor.insert(0);
	mhor.insert(m);
	mp_hor[m]++;
	mp_ver[n]++;
	while (q--) {
		char ch;
		int x;
		cin >> ch >> x;
		if (ch == 'H') {
			auto it = hor.lower_bound(x);;
			int r = *it;
			--it;
			int l = *it;
			if (!(--mp_hor[r - l])) {
				mhor.erase(r - l);
			} 
			if (!(mp_hor[x - l]++)) {
				mhor.insert(x - l);
			} 
			if (!(mp_hor[r - x]++)) {
				mhor.insert(r - x);
			}
			hor.insert(x);
		} else {
			auto it = ver.lower_bound(x);
			int r = *it;
			--it;
			int l = *it;
			if (!(--mp_ver[r - l])) {
				mver.erase(r - l);
			} 
			if (!(mp_ver[x - l]++)) {
				mver.insert(x - l);
			} 
			if (!(mp_ver[r - x]++)) {
				mver.insert(r - x);
			}
			ver.insert(x);
		}
		long long a = *(mhor.begin()), b = *(mver.begin());
		printf("%lld\n", a * b);
	}
	return 0;
}