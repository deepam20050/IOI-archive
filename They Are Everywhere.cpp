// http://codeforces.com/problemset/problem/701/C
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

char s[N];
map <char, int> mp, mp2;

int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	for (int i = 0; i < n; ++i) {
		mp[s[i]] = 1;
	}
	const int total = mp.size();
	int ans = 1e9, j = 0, sum = 0;
	for (int i = 0; i < n; ++i) {
		while (j < n && sum < total) {
			if (mp2[s[j]] == 0) {
				++sum;
			}
			++mp2[s[j]];
			++j;
		}
		if (sum == total) {
			ans = min(ans, j - i);
		}
		--mp2[s[i]];
		if (mp2[s[i]] == 0) {
			--sum;
		}
	}
	printf("%d\n",ans);
	return 0;
}