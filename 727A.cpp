// http://codeforces.com/problemset/problem/727/A
// AC

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

queue <ll> q;
unordered_map <ll,ll> mp;
set <ll> used;
vector <ll> v;

int main() {
	ll a,b;
	scanf("%lld %lld",&a,&b);

	mp[a] = -1;
	bool flag = 1;
	q.push(a);
	while (!q.empty()) {
		ll x = q.front(); q.pop();
		if (x == b) {
			flag = 0;
			break;
		}
		used.insert(x);

		if (2 * x <= b && used.find(2 * x) == used.end()) {
			q.push(2*x);
			mp[2*x] = x;
		} 
		if (10 * x + 1 <= b && used.find(10 * x + 1) == used.end()) {
			q.push(10 * x + 1);
			mp[10 * x + 1] = x;
		}
	}

	if (flag) {
		puts("NO");
		return 0;
	}

	puts("YES");

	for (int x = b; mp[x] != -1; x = mp[x]) {
		v.emplace_back(x);
	}

	printf("%lu\n",v.size() + 1);
	printf("%lld",a);
	for (int i = v.size() - 1; i >= 0; --i) {
		printf(" %lld",v[i]);
	}

	return 0;
}