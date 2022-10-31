// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 305;

pair < int, int > dragons[N];
long long dp[N][N];
int r;
int c;
int k;
int d;

long long dist (int a, int b) {
	return 1LL * (abs(dragons[a].first - dragons[b].first) + abs(dragons[a].second - dragons[b].second));
}

int main() {
	scanf("%d %d %d %d", &r, &c, &k, &d);
	for (int i = 1; i <= d; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		dragons[i] = {x, y};
	}
	sort(dragons, dragons + d + 1);
	for (int i = 0; i <= d; ++i) {
		for (int j = 1; j <= k; ++j) {
			dp[i][j] = 1LL << 60;
		}
	}
	for (int i = d - 1; i >= 0; --i) {
		for (int j = 1; j <= k; ++j) {
			for (int l = i + 1; l <= d; ++l) {
				dp[i][j] = min(dp[i][j], dp[l][j - 1] + dist(i, l));
			}
		}
	}
	printf("%lld\n", dp[0][k]);
	return 0;
}