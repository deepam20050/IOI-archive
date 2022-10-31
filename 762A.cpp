// http://codeforces.com/contest/762/problem/A

#include "bits/stdc++.h"

using namespace std;

vector <long long> v;

int main() {
	long long n, k;
	scanf("%lld %lld", &n, &k);
	for (long long i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			v.emplace_back(i);
			if ((n / i) != i) {
				v.emplace_back(n / i);
			}
		}
	}
	sort(v.begin(), v.end());
	v.size() < k ? puts("-1") : printf("%lld\n", v[k - 1]);
	return 0;
}