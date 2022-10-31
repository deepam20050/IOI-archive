// https://www.codechef.com/problems/LIKECS02

#include <bits/stdc++.h>

using namespace std;

int a[123];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		bool ok = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0, val = i; j < n; ++j, ++val) {
				a[j] = val;
			}
			double sum = 0.0;
			for (int j = 0; j < n; ++j) {
				for (int k = j; k < n; ++k) {
					int dist = k - j + 1;
					if (dist & 1) {
						sum += a[(j + k) / 2];
					} else {
						sum += (a[(j + k) / 2] + a[(j + k + 1) / 2]) / 2.0;
					}
				}
			}
			double m = (n * (n + 1)) / 2.0;
			double val = sum / m;
			double x = n - 1.0;
			double y = n + 1.0;
			if (x <= val && val <= y) {
				ok = 1;
				for (int j = 0; j < n; ++j) {
					printf("%d ", a[j]);
				}
				break;
			}
		}
		if (!ok) {
			printf("-1");
		}
		puts("");
	}
	return 0;
}