#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n, s;
	cin >> n >> s;
	if (n == s) {
		cout << n + 1;
		return 0;
	}
	for (long long b = 2; b * b <= n; ++b) {
		auto x = n, sum = 0LL;
		while (x) {
			sum += x % b;
			x /= b;
		}
		if (sum == s) {
			cout << b;
			return 0;
		}
	}
	for (long long i = 1; i * i <= (n - s); ++i) {
		if ((n - s) % i == 0) {
			auto b = (n - s) / i;
			if (b * b <= n) continue;
			cout << b;
			return 0;
		}
	}
	puts("-1");
	return 0;
}