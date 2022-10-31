// http://codeforces.com/contest/854/problem/B

#include "bits/stdc++.h"

using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	if (!k) {
		puts("0 0");
		return 0;
	}
	printf("%d %d", min(n - k, 1) , min(n - k, 2 * k));
	return 0;
}