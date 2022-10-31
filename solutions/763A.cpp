// http://codeforces.com/problemset/problem/763/A
// AC
// Good solution by Yuhauo

#include <bits/stdc++.h>

using namespace std;

const int N = 123456;

int x[N], y[N], color[N];
unordered_map <int,int> mp;

int main() {
	int n;
	scanf("%d",&n);

	for (int i = 0; i < n-1; ++i) {
		scanf("%d %d",x + i, y + i);
	}

	for (int i = 1; i <= n; ++i) {
		scanf("%d",color + i);
	}
	int m = 0;
	for (int i = 0; i < n-1; ++i) {
		if (color[x[i]] != color[y[i]]) {
			++mp[x[i]];
			++mp[y[i]];
			m++;
		}
	}
	if (m == 0) {
		printf("YES\n1\n");
		return 0;
	}
	int ans = -1;
	for (const auto &e: mp) {
		if (e.second == m) {
			ans = e.first;
			break;
		}
	}

	if (ans == -1) puts("NO");
	else printf("YES\n%d\n",ans);

	return 0;
}