// https://www.codechef.com/problems/GRGUY
// AC

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5, INF = 1e9;

string l1, l2;
int dp[N][2];

int main() {
	int t;
	scanf("%d",&t);

	while (t--) {
		cin >> l1 >> l2;
		int n = l1.size();

		dp[0][0] = (l1[0] == '.' ? 0 : INF);
		dp[0][1] = (l2[0] == '.' ? 0 : INF);
		bool flag = 0;
		for (int i = 1; i < n; ++i) {
			if (l1[i] == l2[i] && l1[i] == '#') {
				flag = 1;
				break;
			}
			if (l1[i] == '#') {
				dp[i][0] = INF;
			} else if (l2[i] == '#') {
				dp[i][1] = INF;
			}

			if (l1[i] == '.') {
				dp[i][0] = min(dp[i-1][0], 1 + dp[i-1][1]);
			} 
			if (l2[i] == '.') {
				dp[i][1] = min(dp[i-1][1], 1 + dp[i-1][0]);
			}
			if (l1[i] == '.') {
				dp[i][0] = min(dp[i][0], 1 + dp[i][1]);
			}
			if (l2[i] == '.') {
				dp[i][1] = min(dp[i][1], 1 + dp[i][0]);
			}
		}
		if (l1[0] == l2[0] && l1[0] == '#') {
			flag = 1;
		}
		if (flag) {
			puts("No");
		} else {
			printf("Yes\n%d\n",min(dp[n-1][0],dp[n-1][1]));
		}
	}


	return 0;
}