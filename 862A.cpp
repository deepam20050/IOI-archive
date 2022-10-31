// http://codeforces.com/contest/862/problem/A

#include "bits/stdc++.h"

using namespace std;

int a[200];

int main() {
	int n, x;
	scanf("%d %d", &n, &x);
	while (n--) {
		int z;
		scanf("%d", &z);
		a[z] = 1;
	}
	int ans = 0;
	for (int i = 0; i < x; ++i) {
		if (!a[i]) {
			++ans;
		}
	}
	//cout << ans << '\n';
	if (a[x]) {
		ans++;
	}
	cout << ans;
	return 0;
}