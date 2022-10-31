// http://codeforces.com/problemset/problem/659/C
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

long ar[N];

int main() {
	int n; 
	long m;
	scanf("%d %ld", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%ld", ar + i);
	}
	sort(ar, ar + n);
	vector <long> v;
	for (int i = 1, sum = 0; i <= m; ++i) {
		if (sum + i <= m && !binary_search(ar, ar + n, i)) {
			v.emplace_back(i);
			m -= i;
		}	
	}
	printf("%lu\n",v.size());
	for (const auto &e: v) {
		printf("%ld ", e);
	}
	return 0;
}