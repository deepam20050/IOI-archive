#include <bits/stdc++.h>

using namespace std;

int main() {
	double a, b;
	scanf("%lf %lf", &a, &b);
	if (a < b) {
		return !printf("-1");
	}
	int v2 = (a + b) / 2;
	double ans = (a + b) / (2.0 * v2);
	printf("%.10f", ans);
	return 0;
}