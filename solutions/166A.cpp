// http://codeforces.com/problemset/problem/166/A
// AC

#include <bits/stdc++.h>

using namespace std;
using pi = pair<int,int>;

pi p[51];

bool cmp(const pi &a, const pi &b) {
	if (a.first == b.first)
		return a.second <= b.second;
	return a.first > b.first;
}

int main() {
	int n,k;
	scanf("%d %d",&n,&k);

	for (int i = 0; i < n; ++i) {
		scanf("%d %d",&p[i].first, &p[i].second);
	}

	stable_sort(p,p+n,cmp);

	pi x = p[k-1];
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (p[i] == x) ++ans;
	}

	printf("%d\n",ans);

	return 0;
}