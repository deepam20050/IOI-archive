// http://codeforces.com/problemset/problem/797/B

#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, odd = 1e9, odd2 = -1e9, sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		if (x >= 0) {
			sum += x;
		}
		if (x >= 1 && (x & 1)) {
			odd = min(odd, x);
		} 
		if (x < 0 && ((-x) & 1)) {
			odd2 = max(x, odd2);
		}
	}
	if (sum % 2 == 0) {
		sum -= min(odd, -odd2);
	}
	printf("%d", sum);
	return 0;
}