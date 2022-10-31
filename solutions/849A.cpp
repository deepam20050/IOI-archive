// http://codeforces.com/contest/849/problem/A

#include "bits/stdc++.h"

using namespace std;

const int N = 110;

int a[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	if ((n & 1) && (a[0] & 1) && (a[n - 1] & 1)) {
		puts("Yes");
	} else {
		puts("No");
	}
	return 0;
}