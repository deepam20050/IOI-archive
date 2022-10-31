#include <bits/stdc++.h>

using namespace std;

void insert (int x) {
	int node = 1;
	for (int i = 31; i >= 0; --i) {
		
	}
}	

int main() {
	scanf("%d %lld", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", arr + i);
		pref[i] = pref[i - 1] ^ arr[i];
	}
	for (int i = 1; i <= n; ++i) {
		insert(pref[i]);
	}
	int l = 0;
	int r = 1 << 21;
	for (int i = 0; i < 25; ++i) {
		int m = l + r >> 1;
		int howmany = f(m);
		if (howmany == k - 1) {
			printf("%d\n", m);
			return 0;
		} else if (howmany > k) {
			l = m;
		} else {
			r = m;
		}
	}
	return 0;
}