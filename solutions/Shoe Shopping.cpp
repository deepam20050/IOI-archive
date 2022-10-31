#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

double dp[N];
double arr[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lf", &arr[i]);
	}
	dp[1] = arr[1];
	dp[2] = min(arr[1], arr[2]) * 0.5 + max(arr[1], arr[2]);
	for (int i = 3; i <= n; ++i) {
		// dp[i] = arr[i] + dp[i - 1];
		// double mini = min(arr[i], min(arr[i - 1], arr[i - 2]));
		// if (mini == arr[i]) {
		// 	dp[i] = min(dp[i], dp[i - 1]);
		// } 
		// if (mini == arr[i - 1]) {
		// 	dp[i] = min(dp[i], arr[i] + dp[i - 2]);
		// }
		// if (mini == arr[i - 2]) {
		// 	dp[i] = min(dp[i], min(arr[i], arr[i - 1]) * 0.5 + max(arr[i], arr[i - 1]) + dp[i - 3]);
		// }
		// mini = min(arr[i], arr[i - 1]);
		// if (mini == arr[i]) {
		// 	dp[i] = min(dp[i], arr[i] * 0.5 + dp[i - 1]);
		// }
		// if (mini == arr[i - 1]) {
		// 	dp[i] = min(dp[i], arr[i - 1] * 0.5 + arr[i] + dp[i - 2]);
		// }
		dp[i] = arr[i] + dp[i - 1];
		dp[i] = min(min(arr[i], arr[i - 1]) * 0.5 + max(arr[i], arr[i - 1]) + dp[i - 2], arr[i] + arr[i - 1] + arr[i - 2] - min(arr[i], min(arr[i - 1], arr[i - 2])) + dp[i - 3]);
	}
	printf("%.2f\n", dp[n]);
	return 0;
}