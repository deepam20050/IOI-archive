// http://codeforces.com/problemset/problem/567/C
// AC

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5+10;

ll ar[N];
unordered_map<ll,ll> dp, cnt;

int main() {
	int n,k;
	scanf("%d %d",&n,&k);

	for (int i = 0; i < n; ++i) {
		scanf("%lld",&ar[i]);
	}

	ll ans = 0;
	
	for (int i = n-1; i >= 0; --i) {
		ll a = ar[i];
		ll ak = ar[i] * k;
		ans += dp[ak];
		dp[a] += cnt[ak];
		++cnt[a];
	}

	printf("%lld\n",ans);

	return 0;
}