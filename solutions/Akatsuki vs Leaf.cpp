// https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/practice-problems/algorithm/akatsuki-vs-leaf-circuit/description/

#include <bits/stdc++.h>

using namespace std;

const int M = 1 << 21, N = 20, oo = 1 << 30;

int dp[M];
int ax[N], ay[N], lx[N], ly[N];

int abso(int x) {
	return x < 0 ? -x : x;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", ax + i, ay + i);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", lx + i, ly + i);
	}
	for (int i = 0; i < (1 << n); ++i) {
		dp[i] = oo;
	}
	dp[0] = 0;
	for (int i = 0; i < 1 << n; ++i) {
		int x = __builtin_popcount(i);
		for (int j = 0; j < n; ++j) {
			if ((i & (1 << j)) == 0) {
				dp[i | (1 << j)] = min(dp[i | (1 << j)], dp[i] + abso(ax[x] - lx[j]) + abso(ay[x] - ly[j]));
			} 
		}
	}
	printf("%d", dp[(1 << n) - 1]);
	return 0;
}