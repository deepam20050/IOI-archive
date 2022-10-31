// http://codeforces.com/contest/165/problem/C
// AC


#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

char s[N];
int cnt[N];

int main() {
	int k;
	scanf("%d",&k);
	scanf("%s",s);
	int n = strlen(s);
	long long ans = 0;
	cnt[0] = 1;
	for (int i = 0, ones = 0; i < n; ++i) {
		if (s[i] == '1') ++ones;
		if (ones >= k)
			ans += cnt[ones - k];
		++cnt[ones];
	}

	printf("%lld\n",ans);
	return 0;
}