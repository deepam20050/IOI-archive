// http://codeforces.com/contest/625/problem/A
// AC

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	ll n, a, b, c, ans = 0;
	cin >> n >> a >> b >> c;	
	if (b - c < a && n >= c && b - c >= 0) {
		ans += (n - c)/(b - c);
	}
	n -= ans * (b - c);
	ans += n/a;
	printf("%lld",ans);
	return 0;
}