#include <bits/stdc++.h>

using namespace std;

const int LN = 61;

inline int solve (int bitsb, int bitsa, int trail0) {
	return bitsb - bitsa + trail0;
}

inline int count_trail0 (long long x) {
  int cnt = 0;
  while (!(x & 1LL)) {
    x >>= 1LL;
    cnt++;
  }
  return cnt;
}

int count_trail1 (long long x) {
	int cnt = 0;
	for (int i = 0; i < LN; ++i) {
		if (!(x & (1LL << i))) {
			break;
		}
		++cnt;
	}
	return cnt;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		long long a, b;
		scanf("%lld %lld", &a, &b);
		if (a == b) {
			puts("0");
			continue;
		}
		if (b == 1 && a == 0) {
			puts("1");
			continue;
		}
		if (b == 0) {
			puts("-1");
			continue;
		}
		int bitsa = __builtin_popcountll(a), bitsb = __builtin_popcountll(b), trail0 = count_trail0(b);
		if (bitsa < bitsb) {
			printf("%d\n", solve(bitsb, bitsa, trail0));
			continue;
		}
		if (bitsa > bitsb) {
			int ans = 2e9;
			int excess = bitsb - bitsa;
			for (int i = 0; i < LN; ++i) {
				if (i >= excess && i <= bitsa && bitsb >= bitsa - i + 1) {
					ans = min(ans, 1 + solve(bitsb, bitsa - i + 1, trail0));
				}
			}
			printf("%d\n", ans);
			continue;
		}
		bool lst = a & 1;
		if (!lst) {
			printf("%d\n", trail0);
			continue;
		}
		int trai1 = count_trail1(b);
		if (trai1 <= 2) {
			puts("2");
			continue;
		}
		long long a2 = a ^ 1LL;
		int trail0_2 = count_trail0(a2) - 1;
		printf("%d\n", trail0_2);
	}
	return 0;
}