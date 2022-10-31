// http://codeforces.com/problemset/problem/600/B
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5;

long a[N];

int main() {
	int n,m;
	scanf("%d %d",&n,&m);

	for (int i = 0; i < n; ++i) {
		scanf("%ld",&a[i]);
	}
	sort(a,a+n);
	
	for (int i = 0; i < m; ++i) {
		long x;
		scanf("%ld",&x);
		cout << (upper_bound(a,a+n,x) - a) << " "; 
	}

	return 0;
}