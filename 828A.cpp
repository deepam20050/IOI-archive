// http://codeforces.com/contest/828/problem/A
// Read the problem statement "carefully"

#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);
	int ans = 0, otherguy = 0;
	while (n--) {
		int x;
		scanf("%d", &x);
		if (x == 1) {
			if (a - 1 >= 0) {
				--a;
			} else if (b - 1 >= 0) {
				--b;
				++otherguy;
			} else if (otherguy > 0) {
				--otherguy;
			} else {
				++ans;
			}
		} else {
			if (b - 1 >= 0) {
				--b;
			} else {
				ans += 2;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}