// http://codeforces.com/problemset/problem/779/C
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5;

pair <int, int> ar[N];

bool cmp(pair <int, int> p1, pair <int, int> p2) {
	return p1.first - p1.second < p2.first - p2.second;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &ar[i].first);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &ar[i].second);
	}
	sort(ar, ar + n, cmp);
	int ans = 0;
	for (int i = 0; i < k; ++i) {
		ans += ar[i].first;
	}
	while (k < n) {
		ans += min(ar[k].first, ar[k].second);
		++k;
	}
	printf("%d\n",ans);
	return 0;
}