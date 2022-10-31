// http://codeforces.com/contest/545/problem/D

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int a[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	sort(a, a + n);
	long long sum = 0;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (sum > a[i]) {
			continue;
		}
		++ans;
		sum += a[i];
	}
	printf("%d", ans);
	return 0;
}