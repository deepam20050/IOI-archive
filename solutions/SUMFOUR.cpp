// http://www.spoj.com/problems/SUMFOUR/
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 2500;

int a[N], b[N], c[N], d[N];
unordered_map <int, int> two;

int main() {
	int n;
	scanf("%d",&n);

	for (int i = 0; i < n; ++i) {
		scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
	}

	two.reserve(2*n*n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			++two[c[i] + d[j]];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			long val = a[i] + b[j];
			long rem = -val;
			ans += two[rem];
		}
	}

	printf("%d\n",ans);

	return 0;
}