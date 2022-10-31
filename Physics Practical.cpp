// http://codeforces.com/problemset/problem/253/B
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;

int a[N];

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	sort(a, a + n);
	int j = 0, len = 0;
	for (int i = 0; i < n; ++i) {
		while (j < n && a[j] <= a[i] * 2) {
			++j;
		}
		len = max(len, j - i);
	}
	printf("%d\n",n - len);
	return 0;
}