// http://codeforces.com/problemset/problem/765/C

#include <bits/stdc++.h>

using namespace std;

int main() {
	int k, a, b;
	scanf("%d %d %d", &k, &a, &b);
	if (a >= k && b >= k) {
		printf("%d", a / k + b / k);
	} else if (max(a, b) % k ==0) {
		printf("%d", max(a, b) / k);
	} else {
		puts("-1");
	}
	return 0;
}