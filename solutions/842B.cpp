// http://codeforces.com/contest/842/problem/B

#include "bits/stdc++.h"

using namespace std;

int main() {
	int r, d;
	scanf("%d %d", &r, &d);
	int n;
	scanf("%d", &n);
	int ans = 0;
	while (n--) {
		int x, y, ra;
		scanf("%d %d %d", &x, &y, &ra);
		int d1 = (r - ra) * (r - ra);
		int d2 = (r - d + ra) * (r - d + ra);
		int d3 = x * x + y * y;
		if (d3 <= d1 && d3 >= d2) {
			++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}