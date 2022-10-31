// http://codeforces.com/problemset/problem/660/C

#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

bool a[N];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	int l = 0, r = 0, cnt = 0;
	for (int i = 0, j = 0; i < n; ++i) {
		if (j < i) {
			j = i;
			cnt = 0;
		}
		while (j < n) {
			cnt += !a[j];
			if (cnt > k) {
				cnt -= !a[j];
				break;
			}
			++j;
		}
		if (j - i > r - l) {
			l = i;
			r = j;
		}
		if (cnt > 0) {
			cnt -= !a[i];
		}
	}
	printf("%d\n", r - l);
	for (int i = l; i < r; ++i) {
		a[i] = 1;
	}
	for (int i = 0; i < n; ++i) {
		printf("%d ", a[i]);
	}
	return 0;
}