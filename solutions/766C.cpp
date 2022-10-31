// http://codeforces.com/problemset/problem/766/C

#include "bits/stdc++.h"

using namespace std;

const int N = 1010;
const long long mod = 1e9 + 7;

char s[N];
int a[N];
long long dp[N];
bool there[N];

bool check(int sz) {
	for (int i = 0; i < 26; ++i) {
		if (there[i] && a[i] < sz) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	for (int i = 0; i < 26; ++i) {
		scanf("%d", a + i);
	}
	for (int i = n - 1; i < N; ++i) {
		dp[i] = 1LL;
	}
	int max_sub = 1;
	for (int i = n - 2; i >= 0; --i) {
		memset(there, 0, sizeof there);
		for (int j = i; j < n; ++j) {
			there[s[j] - 'a'] = 1;
			if (check(j - i + 1)) {
				max_sub = max(max_sub, j - i + 1);
				dp[i] += dp[j + 1];
				dp[i] %= mod;
			}
		}
	}
	int min_sub = 0;
	int i = 0;
	while (i < n) {
		memset(there, 0, sizeof there);
		int j = i;
		while (j < n) {
			there[s[j] - 'a'] = 1;
			if (!check(j - i + 1)) {
				break;
			}
			++j;
		}
		i = j;
		++min_sub;
	}
	printf("%lld\n%d\n%d", dp[0], max_sub, min_sub);
	return 0;
}