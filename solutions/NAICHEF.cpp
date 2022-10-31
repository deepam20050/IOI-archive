#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n, a, b;
		scanf("%d %d %d", &n, &a, &b);
		int cnta = 0;
		int cntb = 0;
		for (int i = 0, x; i < n; ++i) {
			scanf("%d", &x);
			cnta += x == a;
			cntb += x == b;
		}
		printf("%.7f\n", (double)(cnta * cntb)/(double)(n * n));
	}
	return 0;
}