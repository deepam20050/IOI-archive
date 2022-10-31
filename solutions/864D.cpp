// http://codeforces.com/problemset/problem/864/D

#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int a[N];
int cnt[N];
bool used[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		++cnt[a[i]];
	}
	int aage = 1, ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (cnt[a[i]] > 1) {
			while (cnt[aage]) {
				++aage;
			}
			if (aage > a[i] && !used[a[i]]) {
				used[a[i]] = 1;
				continue;
			}
			--cnt[a[i]];
			a[i] = aage;
			++cnt[aage];
			used[aage] = 1;
			++ans;
		}
	}
	printf("%d\n", ans);
	for (int i = 1; i <= n; ++i) {
		printf("%d ", a[i]);
	}
	return 0;
}